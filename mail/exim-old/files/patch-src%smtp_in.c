*** src/smtp_in.c Thu Apr  4 13:56:20 2002
--- src/smtp_in.c	Thu Aug 14 09:09:33 2003
***************
*** 2021,2033 ****

      if (!check_helo(smtp_data))
        {
!       char *s;
!       smtp_printf("501 syntactically invalid %s argument(s)\r\n", hello);
!       if (*smtp_data == 0) strcpy(smtp_data, "(no argument given)");
!       s = string_printing(smtp_data);
        log_write(0, LOG_MAIN|LOG_REJECT, "rejected %s from %s: syntactically "
          "invalid argument(s): %s", hello,
!         (sender_fullhost == NULL)? "local process" : sender_fullhost, s);
        break;
        }

--- 2021,2032 ----

      if (!check_helo(smtp_data))
        {
!       smtp_printf("501 Syntactically invalid %s argument(s)\r\n", hello);
        log_write(0, LOG_MAIN|LOG_REJECT, "rejected %s from %s: syntactically "
          "invalid argument(s): %s", hello,
!         (sender_fullhost == NULL)? "local process" : sender_fullhost,
!         (*smtp_data == 0)? "(no argument given)" :
!                            string_printing(smtp_data));
        break;
        }
