*** src/rda.c.orig	Wed Dec 18 10:28:03 2002
--- src/rda.c	Wed Dec 18 11:35:25 2002
***************
*** 489,494 ****
--- 489,495 ----
  int yield, status;
  pid_t pid;
  uschar *data;
+ void (*oldsignal)(int);

  DEBUG(D_route) debug_printf("rda_interpret (%s): %s\n",
    (rdata->isfile)? "file" : "string", rdata->string);
***************
*** 542,547 ****
--- 543,553 ----
    log_write(0, LOG_MAIN|LOG_PANIC_DIE, "creation of pipe for filter or "
      ":include: failed for %s: %s", rname, strerror(errno));

+ /* Ensure that SIGCHLD is set to SIG_DFL before forking, so that the child
+ process can be waited for. We sometimes get here with it set otherwise. Save
+ the old state for resetting on the wait. */
+
+ oldsignal = signal(SIGCHLD, SIG_DFL);
  if ((pid = fork()) == 0)
    {
    header_line *waslast = header_last;   /* Save last header */
***************
*** 831,836 ****
--- 837,843 ----
    }

  close(fd);
+ signal(SIGCHLD, oldsignal);   /* restore */
  return yield;

  /* Come here is there's a shambles in transferring the data over the pipe. */
