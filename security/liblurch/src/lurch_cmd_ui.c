#include <inttypes.h>
#include <stdlib.h>
#include <glib.h>
#include <purple.h>

#include "jutil.h"

#include "libomemo.h"
#include "lurch_api.h"

static void lurch_cmd_print(PurpleConversation * conv_p, const char * msg) {
  purple_conversation_write(conv_p, "lurch", msg, PURPLE_MESSAGE_SYSTEM | PURPLE_MESSAGE_NO_LOG, time((void *) 0));  
}

static void lurch_cmd_print_err(PurpleConversation * conv_p, const char * msg) {
  purple_conversation_write(conv_p, "lurch", msg, PURPLE_MESSAGE_SYSTEM | PURPLE_MESSAGE_NO_LOG | PURPLE_MESSAGE_ERROR, time((void *) 0));  
}

static void lurch_cmd_help(PurpleConversation * conv_p) {
  const char * help_message = 
    "The following commands exist to interact with the lurch plugin:\n\n"
    " - '/lurch enable': Enables OMEMO encryption for this conversation. On by default for regular conversations, off for group chats.\n"
    " - '/lurch disable': Disables OMEMO encryption for this conversation.\n"
    "\n"
    " - '/lurch id list': Displays this account's device list.\n"
    " - '/lurch id remove <id>': Removes the device ID <id> from this account's device list.\n"
    "\n"
    " - '/lurch fp show': Displays this device's key fingerprint.\n"
    " - '/lurch fp list': Displays the fingerprints of all your devices.\n"
    " - '/lurch fp contact': Displays the fingerprints of all of your conversation partner's devices.\n"
    "\n"
    " - '/lurch status': Shows the OMEMO status of this conversation from your point of view.\n"
    " - '/lurch help': Displays this message.";

    lurch_cmd_print(conv_p, help_message);
}

void lurch_id_list_print(int32_t err, GList * id_list, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;

  char * temp_msg_1 = g_strdup_printf("\nYour devicelist is:\n%i (this device)\n", omemo_devicelist_list_data(id_list));
  char * temp_msg_2 = (void *) 0;
  char * temp_msg_3 = (void *) 0;

  GList * curr_p = (void *) 0;

  if (err) {
    lurch_cmd_print_err(conv_p, "An error occured when trying to retrieve your ID list. Check the debug log for details.");
    return;
  }

  for (curr_p = id_list->next; curr_p; curr_p = curr_p->next) {
    temp_msg_2 = g_strdup_printf("%i\n", omemo_devicelist_list_data(curr_p));

    temp_msg_3 = g_strconcat(temp_msg_1, temp_msg_2, NULL);

    g_free(temp_msg_1);
    temp_msg_1 = temp_msg_3;
    g_free(temp_msg_2);

    temp_msg_2 = (void *) 0;
    temp_msg_3 = (void *) 0;
  }

  lurch_cmd_print(conv_p, temp_msg_1);

  g_free(temp_msg_1);
}

void lurch_id_remove_print(int32_t err, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to remove the ID from your devicelist. Check the debug log for details.");
    return;
  }

  lurch_cmd_print(conv_p, "Successfully removed the ID from your devicelist.");
}

void lurch_enable_print(int32_t err, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to enable OMEMO for this conversation.");
    return;
  }
  
  purple_conversation_autoset_title(conv_p);
  lurch_cmd_print(conv_p, "Successfully enabled OMEMO.");
}

void lurch_disable_print(int32_t err, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to disable OMEMO for this conversation.");
    return;
  }
  
  purple_conversation_autoset_title(conv_p);
  lurch_cmd_print(conv_p, "Successfully disabled OMEMO.");
}

void lurch_fp_show_print(int32_t err, const char * fp_printable, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;
  char * msg = (void *) 0;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to get this device's fingerprint. Check the debug log for details.");
    return;
  }

  msg = g_strdup_printf("This device's fingerprint is %s.", fp_printable);
  lurch_cmd_print(conv_p, msg);

  g_free(msg);
}

void lurch_fp_print(int32_t err, GHashTable * id_fp_table, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;

  GString * msg = (void *) 0;
  GList * key_list = (void *) 0;
  const GList * curr_p = (void *) 0;
  const char * fp = (void *) 0;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to get the fingerprints. Check the debug log for details.");
    return;
  }

  if (!id_fp_table) {
    lurch_cmd_print(conv_p, "The devicelist is empty, so there is nothing to show!");
    return;
  }

  msg = g_string_new("\n");
  key_list = g_hash_table_get_keys(id_fp_table);
  for (curr_p = key_list; curr_p; curr_p = curr_p->next) {
    fp = (char *) g_hash_table_lookup(id_fp_table, curr_p->data);
    g_string_append_printf(msg, "%i's fingerprint:\n%s\n", *((uint32_t *) curr_p->data), fp ? fp : "(no session)");
  }

  lurch_cmd_print(conv_p, msg->str);

  g_string_free(msg, TRUE);
  g_list_free(key_list);
}

void lurch_status_im_print(int32_t err, lurch_status_t status, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;
  const char * msg = (void *) 0;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to get the conversation status. Check the debug log for details.");
    return;
  }

  switch (status) {
    case LURCH_STATUS_DISABLED:
      msg = "You disabled OMEMO for this conversation. Type '/lurch enable' to switch it back on.";
      break;
    case LURCH_STATUS_NOT_SUPPORTED:
      msg = "Your contact does not support OMEMO. No devicelist could be found.";
      break;
    case LURCH_STATUS_NO_SESSION:
      msg = "Your contact supports OMEMO, but you have not established a session yet. Just start messaging!";
      break;
    case LURCH_STATUS_OK:
      msg = "OMEMO is enabled for this conversation. You can turn it off by typing '/lurch disable'.";
      break;
    default:
      msg = "Received unknown status code.";
  }

  lurch_cmd_print(conv_p, msg);
}

void lurch_status_chat_print(int32_t err, lurch_status_chat_t status, void * user_data_p) {
  PurpleConversation * conv_p = (PurpleConversation *) user_data_p;
  const char * msg = (void *) 0;

  if (err) {
    lurch_cmd_print_err(conv_p, "Failed to get the conversation status. Check the debug log for details.");
    return;
  }

  switch (status) {
    case LURCH_STATUS_CHAT_DISABLED:
      msg = "OMEMO was not enabled for this conversation. Type '/lurch enable' to switch it on.";
      break;
    case LURCH_STATUS_CHAT_ANONYMOUS:
      msg = "The MUC is set to anonymous, which means that the members' JIDs are inaccessible and OMEMO will not work. Ask a moderator to change this.";
      break;
    case LURCH_STATUS_CHAT_NO_DEVICELIST:
      msg = "Could not access the OMEMO devicelist of at least one of the chat members. Make sure every member is in every other member's contact list.";
      break;
    case LURCH_STATUS_CHAT_OK:
      msg = "OMEMO is enabled for this conversation and everything should work. You can turn it off by typing '/lurch disable'.";
      break;
    case LURCH_STATUS_CHAT_NO_JIDS:
      msg = "The MUC is not anonymous, but the members' JIDs are inaccessible. This can happen if the MUC was reconfigured to be non-anonymous while this client was joined. Rejoining the chat will probably fix the issue.";
      break;
    default:
      msg = "Received unknown status code.";
  }

  lurch_cmd_print(conv_p, msg);
}

static void lurch_cmd_id(PurpleConversation * conv_p, const char * arg, const char * param) {
  PurpleAccount * acc_p = purple_conversation_get_account(conv_p);
  void * plugins_handle = purple_plugins_get_handle();

  if (!g_strcmp0(arg, "list")) {
    purple_signal_emit(plugins_handle, "lurch-id-list", acc_p, lurch_id_list_print, conv_p);
  } else if (!g_strcmp0(arg, "remove")) {
    if (!param) {
      lurch_cmd_print_err(conv_p, "You have to specify the device ID to remove.");
    } else {
      purple_signal_emit(plugins_handle, "lurch-id-remove", acc_p, strtol(param, (void *) 0, 10), lurch_id_remove_print, conv_p);
    }
  } else {
    lurch_cmd_print(conv_p, "Valid arguments for 'id' are list' and 'remove <id>'.");
  }
}

static void lurch_cmd_enable(PurpleConversation * conv_p) {
  char * bare_jid = (void *) 0;
  void * plugins_handle = purple_plugins_get_handle();
  PurpleConversationType conv_type = purple_conversation_get_type(conv_p);
  PurpleAccount * acc_p = purple_conversation_get_account(conv_p);
  const char * conv_name = purple_conversation_get_name(conv_p);

  switch (conv_type) {
    case PURPLE_CONV_TYPE_IM:
      bare_jid = jabber_get_bare_jid(conv_name);
      purple_signal_emit(plugins_handle, "lurch-enable-im", acc_p, bare_jid, lurch_enable_print, conv_p);
      break;
    case PURPLE_CONV_TYPE_CHAT:
      purple_signal_emit(plugins_handle, "lurch-enable-chat", acc_p, conv_name, lurch_enable_print, conv_p);
      break;
    default:
      lurch_cmd_print_err(conv_p, "Conversation type not supported.");
      break;
  }

  g_free(bare_jid);
}

static void lurch_cmd_disable(PurpleConversation * conv_p) {
  char * bare_jid = (void *) 0;
  void * plugins_handle = purple_plugins_get_handle();
  PurpleConversationType conv_type = purple_conversation_get_type(conv_p);
  PurpleAccount * acc_p = purple_conversation_get_account(conv_p);
  const char * conv_name = purple_conversation_get_name(conv_p);

  switch (conv_type) {
    case PURPLE_CONV_TYPE_IM:
      bare_jid = jabber_get_bare_jid(conv_name);
      purple_signal_emit(plugins_handle, "lurch-disable-im", acc_p, bare_jid, lurch_disable_print, conv_p);
      break;
    case PURPLE_CONV_TYPE_CHAT:
      purple_signal_emit(plugins_handle, "lurch-disable-chat", acc_p, conv_name, lurch_disable_print, conv_p);
      break;
    default:
      lurch_cmd_print_err(conv_p, "Conversation type not supported.");
      break;
  }

  g_free(bare_jid);
}

static void lurch_cmd_fp(PurpleConversation * conv_p, const char * arg) {
  PurpleAccount * acc_p = purple_conversation_get_account(conv_p);
  void * plugins_handle = purple_plugins_get_handle();
  char * conv_bare_jid = (void *) 0;

  if (!g_strcmp0(arg, "show")) {
    purple_signal_emit(plugins_handle, "lurch-fp-get", acc_p, lurch_fp_show_print, conv_p);
  } else if (!g_strcmp0(arg, "list")) {
    lurch_cmd_print(conv_p, "Your devices' fingerprints are:");
    purple_signal_emit(plugins_handle, "lurch-fp-list", acc_p, lurch_fp_print, conv_p);
  } else if (!g_strcmp0(arg, "contact")) {
    lurch_cmd_print(conv_p, "Your contact's devices' fingerprints are:");
    conv_bare_jid = jabber_get_bare_jid(purple_conversation_get_name(conv_p));
    purple_signal_emit(plugins_handle, "lurch-fp-other", acc_p, conv_bare_jid, lurch_fp_print, conv_p);
  } else {
    lurch_cmd_print(conv_p, "Valid arguments for 'fp' are 'show', 'list', and 'contact'.");
  }

  g_free(conv_bare_jid);
}

static void lurch_cmd_status(PurpleConversation * conv_p) {
  char * bare_jid = (void *) 0;
  const char * conv_name = purple_conversation_get_name(conv_p);
  PurpleConversationType conv_type = purple_conversation_get_type(conv_p);
  void * plugins_handle = purple_plugins_get_handle();
  PurpleAccount * acc_p = purple_conversation_get_account(conv_p);

  switch (conv_type) {
    case PURPLE_CONV_TYPE_IM:
      bare_jid = jabber_get_bare_jid(conv_name);
      purple_signal_emit(plugins_handle, "lurch-status-im", acc_p, bare_jid, lurch_status_im_print, conv_p);
      break;
    case PURPLE_CONV_TYPE_CHAT:
      purple_signal_emit(plugins_handle, "lurch-status-chat", acc_p, conv_name, lurch_status_chat_print, conv_p);
      break;
    default:
      lurch_cmd_print_err(conv_p, "Conversation type not supported.");
  }

  g_free(bare_jid);
}

PurpleCmdRet lurch_cmd_func(PurpleConversation * conv_p,
                                   const gchar * cmd,
                                   gchar ** args,
                                   gchar ** error,
                                   void * data_p) {
  const char * command = args[0];

  if (!g_strcmp0(command, "help")) {
    lurch_cmd_help(conv_p);
  } else if (!g_strcmp0(command, "enable")) {
    lurch_cmd_enable(conv_p);
  } else if (!g_strcmp0(command, "disable")) {
    lurch_cmd_disable(conv_p);
  } else if (!g_strcmp0(command, "id")) {
    lurch_cmd_id(conv_p, args[1], args[2]);
  } else if (!g_strcmp0(command, "fp")) {
    lurch_cmd_fp(conv_p, args[1]);
  } else if (!g_strcmp0(command, "status")) {
    lurch_cmd_status(conv_p);
  } else {
    lurch_cmd_print(conv_p, "No such command. Type '/lurch help' for a list of available commands.");
  }

  return PURPLE_CMD_RET_OK;
}
