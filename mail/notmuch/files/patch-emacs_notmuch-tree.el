From: William Casarin <jackbox55@gmail.com>

Some are running into undeclarated function errors

> emacs/notmuch-tree.el:1143:1:Warning: the following functions are
>     not known to be defined: notmuch-search-previous-thread,
>     notmuch-search-next-thread, notmuch-tree-from-search-thread

Reported-by: Danilo G. Baio <dbaio@FreeBSD.org>
Signed-off-by: William Casarin <jb55@jb55.com>
--- emacs/notmuch-tree.el.orig	2020-09-06 00:50:03 UTC
+++ emacs/notmuch-tree.el
@@ -41,6 +41,9 @@
 (declare-function notmuch-read-query "notmuch" (prompt))
 (declare-function notmuch-search-find-thread-id "notmuch" (&optional bare))
 (declare-function notmuch-search-find-subject "notmuch" ())
+(declare-function notmuch-search-next-thread "notmuch" ())
+(declare-function notmuch-search-previous-thread "notmuch" ())
+(declare-function notmuch-tree-from-search-thread "notmuch" ())
 
 ;; the following variable is defined in notmuch.el
 (defvar notmuch-search-query-string)
