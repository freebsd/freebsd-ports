*** src/daemon.c  Thu Apr  4 13:56:16 2002
--- src/daemon.c	 Wed Dec  4 11:01:39 2002
***************
*** 590,596 ****
    if (pid_file_path[0] == 0)
      sprintf(buff, "%s/exim-daemon.pid", spool_directory);
    else
!     sprintf(buff, pid_file_path, "");
    }
  else
    {
--- 590,596 ----
    if (pid_file_path[0] == 0)
      sprintf(buff, "%s/exim-daemon.pid", spool_directory);
    else
!     strcpy(buff, pid_file_path);
    }
  else
    {
***************
*** 598,606 ****
      sprintf(buff, "%s/exim-daemon.%d.pid", spool_directory, smtp_port);
    else
      {
!     char dbuff[12];
!     sprintf(dbuff, ".%d", smtp_port);
!     sprintf(buff, pid_file_path, dbuff);
      }
    }

--- 598,604 ----
      sprintf(buff, "%s/exim-daemon.%d.pid", spool_directory, smtp_port);
    else
      {
!     strcpy(buff, pid_file_path);
      }
    }
