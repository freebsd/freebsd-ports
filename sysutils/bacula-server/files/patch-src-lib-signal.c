*** src/lib/signal.c.org	Wed Aug 10 18:35:19 2005
--- src/lib/signal.c	Mon Nov 28 07:31:37 2005
***************
*** 245,251 ****
     sig_names[SIGWAITING] = _("No runnable lwp");
  #endif
  #ifdef SIGLWP
!    sig_name[SIGLWP]     = _("SIGLWP special signal used by thread library");
  #endif
  #ifdef SIGFREEZE
     sig_names[SIGFREEZE] = _("Checkpoint Freeze");
--- 245,251 ----
     sig_names[SIGWAITING] = _("No runnable lwp");
  #endif
  #ifdef SIGLWP
!    sig_names[SIGLWP]     = _("SIGLWP special signal used by thread library");
  #endif
  #ifdef SIGFREEZE
     sig_names[SIGFREEZE] = _("Checkpoint Freeze");
