
#include <sys/types.h>
#include <security/pam_appl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Static variables used to communicate between the conversation function
 * and the server_login function
 */
static char *PAM_username;
static char *PAM_password;

/* PAM conversation function
 */
static int PAM_conv (int num_msg,
                     const struct pam_message **msg,
                     struct pam_response **resp,
                     void *appdata_ptr) {
  int replies = 0;
  struct pam_response *reply = NULL;

  #define COPY_STRING(s) (s) ? strdup(s) : NULL

  reply = malloc(sizeof(struct pam_response) * num_msg);
  if (!reply) return PAM_CONV_ERR;

  for (replies = 0; replies < num_msg; replies++) {
    switch (msg[replies]->msg_style) {
      case PAM_PROMPT_ECHO_ON:
        reply[replies].resp_retcode = PAM_SUCCESS;
        reply[replies].resp = COPY_STRING(PAM_username);
          /* PAM frees resp */
        break;
      case PAM_PROMPT_ECHO_OFF:
        reply[replies].resp_retcode = PAM_SUCCESS;
        reply[replies].resp = COPY_STRING(PAM_password);
          /* PAM frees resp */
        break;
      case PAM_TEXT_INFO:
        /* fall through */
      case PAM_ERROR_MSG:
        /* ignore it, but pam still wants a NULL response... */
        reply[replies].resp_retcode = PAM_SUCCESS;
        reply[replies].resp = NULL;
        break;
      default:
        /* Must be an error of some sort... */
        free (reply);
        return PAM_CONV_ERR;
    }
  }
  *resp = reply;
  return PAM_SUCCESS;
}

static struct pam_conv PAM_conversation = {
    PAM_conv,
    NULL
};

/* Server log in
 * Accepts: user name string
 *          password string
 * Returns: "OK" if password validated, error message otherwise
 */ 
 
char *pwcheck(char *username, char *password)
{
  pam_handle_t *pamh;
  int pam_error;

  /* PAM only handles authentication, not user information. */
  if ( !(username && password && strlen(username) && strlen(password)) )
      return "Incorrect username";

  /* validate password */

  PAM_password = password;
  PAM_username = username;
  fprintf(stderr, "checking %s\n", username);
  pam_error = pam_start("cyrus", username, &PAM_conversation, &pamh);
  if (pam_error == PAM_SUCCESS) 
    pam_error = pam_authenticate(pamh, 0);
    
  if (pam_error == PAM_SUCCESS) 
    pam_error = pam_acct_mgmt(pamh, 0);

  if ( pam_error == PAM_SUCCESS) 
    fprintf(stderr, "\tauthenticated %s\n", username);
  else
    fprintf(stderr, "\tfailed to authenticate %s\n", username);
  
  if(pam_end(pamh, pam_error) != PAM_SUCCESS) {
    pamh = NULL;
    fprintf(stderr, "pwcheck: failed to release authenticator\n");
    exit(1);
  }
  return ( pam_error == PAM_SUCCESS ? "OK" : "Incorrect passwd" );
}


