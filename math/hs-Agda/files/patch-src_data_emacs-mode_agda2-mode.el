https://github.com/agda/agda/pull/6735

--- src/data/emacs-mode/agda2-mode.el.orig	2001-09-09 01:46:40 UTC
+++ src/data/emacs-mode/agda2-mode.el
@@ -261,8 +261,8 @@ CMD is a command; KEYS is its key binding (if any); WH
   "Table of commands, used to build keymaps and menus.
 Each element has the form (CMD &optional KEYS WHERE DESC) where
 CMD is a command; KEYS is its key binding (if any); WHERE is a
-list which should contain 'local if the command should exist in
-the goal menu and 'global if the command should exist in the main
+list which should contain \\='local if the command should exist in
+the goal menu and \\='global if the command should exist in the main
 menu; and DESC is the description of the command used in the
 menus.")
 
@@ -530,7 +530,7 @@ for output and executes the responses, if any.
 Sends the list of strings ARGS to the Agda2 interpreter, waits
 for output and executes the responses, if any.
 
-If SAVE is 'save, then the buffer is saved first.
+If SAVE is \\='save, then the buffer is saved first.
 
 If HIGHLIGHT is non-nil, then the buffer's syntax highlighting
 may be updated. This is also the case if the Agda process is
@@ -759,13 +759,13 @@ The user input is computed as follows:
   contains whitespace, then the input is taken from the
   minibuffer. In this case WANT is used as the prompt string.
 
-* Otherwise (including if WANT is 'goal) the goal contents are
+* Otherwise (including if WANT is \\='goal) the goal contents are
   used.
 
 If the user input is not taken from the goal, then an empty goal
 range is given.
 
-If SAVE is 'save, then the buffer is saved just before the
+If SAVE is \\='save, then the buffer is saved just before the
 command is sent to Agda (if it is sent)."
   (cl-multiple-value-bind (o g) (agda2-goal-at (point))
     (unless g (error "For this command, please place the cursor in a goal"))
@@ -893,7 +893,6 @@ of new goals."
 
 (defun agda2-autoAll ()
   (interactive)
-  "Solves all goals by simple proof search."
   (agda2-go nil nil 'busy t "Cmd_autoAll")
 )
 
@@ -1949,7 +1948,7 @@ the argument is a positive number, otherwise turn it o
 
 (defun agda2-get-agda-program-versions ()
   "Get \"version strings\" of executables starting with
-'agda-mode' in current path."
+\\='agda-mode' in current path."
   (delete-dups
    (mapcar (lambda (path)
              ;; strip 'agda-mode' prefix
