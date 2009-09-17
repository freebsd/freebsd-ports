$FreeBSD$

from http://groups.google.com/group/gnu.emacs.vm.bug/browse_thread/thread/ed559486d3438d6d/db0325050f401ad9?lnk=raot#db0325050f401ad9 ...

Subject: Missing autoload for vm-decode-postponed-mime-message in vm-8.0.12

In vm 8.0.12 it seems there's a missing autoload for the function vm-
decode-postponed-mime-message in vm-pine.el. See:

https://bugzilla.redhat.com/show_bug.cgi?id=474728
https://bugs.launchpad.net/viewmail/+bug/300748

The fix is trivial, patch below

diff -up vm-8.0.12/lisp/vm-pine.el.fix-missing-autoload vm-8.0.12/lisp/vm-pine.el
--- lisp/vm-pine.el.fix-missing-autoload      2008-12-05
23:00:06.0000000
00 +0000
+++ lisp/vm-pine.el   2008-12-05 23:00:43.000000000 +0000
@@ -488,6 +488,7 @@ creation)."
         (error "Folder buffer closed before deletion of source message."))))

 ;;-----------------------------------------------------------------------------
+;;;###autoload
 (defun vm-decode-postponed-mime-message ()
   "Replace the mime buttons by attachment buttons."
   (interactive)

