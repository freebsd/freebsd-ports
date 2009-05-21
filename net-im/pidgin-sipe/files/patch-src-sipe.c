*** src/sipe.c.orig	Sun May 17 19:09:00 2009
--- src/sipe.c	Tue May 19 11:31:02 2009
***************
*** 4734,4742 ****
  	const char *username = purple_account_get_username(account);
  	gc = purple_account_get_connection(account);
  
! 	if (strpbrk(username, " \t\v\r\n") != NULL) {
  		gc->wants_to_die = TRUE;
! 		purple_connection_error(gc, _("SIP Exchange usernames may not contain whitespaces"));
  		return;
  	}
  
--- 4734,4742 ----
  	const char *username = purple_account_get_username(account);
  	gc = purple_account_get_connection(account);
  
! 	if (strpbrk(username, "\t\v\r\n") != NULL) {
  		gc->wants_to_die = TRUE;
! 		purple_connection_error(gc, _("SIP Exchange username contains invalid characters"));
  		return;
  	}
  
***************
*** 4757,4762 ****
--- 4757,4768 ----
  	sip->username = g_strjoin("@", userserver[0], userserver[1], NULL);
  	sip->sipdomain = g_strdup(userserver[1]);
  
+ 	if (strpbrk(sip->username, " \t\v\r\n") != NULL) {
+ 		gc->wants_to_die = TRUE;
+ 		purple_connection_error(gc, _("SIP Exchange usernames may not contain whitespaces"));
+ 		return;
+ 	}
+ 
  	domain_user = g_strsplit(signinname_login[1], "\\", 2);
  	sip->authdomain = (domain_user && domain_user[1]) ? g_strdup(domain_user[0]) : NULL;
  	sip->authuser =   (domain_user && domain_user[1]) ? g_strdup(domain_user[1]) : (signinname_login ? g_strdup(signinname_login[1]) : NULL);
