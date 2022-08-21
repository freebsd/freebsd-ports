#pragma once

#include <glib.h>
#include <purple.h>

PurpleCmdRet lurch_cmd_func(PurpleConversation * conv_p,
                                   const gchar * cmd,
                                   gchar ** args,
                                   gchar ** error,
                                   void * data_p);
