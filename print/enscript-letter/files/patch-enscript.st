--- states/hl/enscript.st.orig	Wed Mar  5 02:31:31 2003
+++ states/hl/enscript.st	Tue Mar  2 06:09:12 2004
@@ -489,6 +489,7 @@
   /\.idl$/					idl;
   /\.(hs|lhs|gs|lgs)$/				haskell;
   /\.(pm|pl)$/					perl;
+  /\.(rb|rbw)$/					ruby;
   /\.(eps|EPS|ps|PS)$/				postscript;
   /\.py$/					python;
   /\.pyx$/					pyrex;
@@ -530,6 +531,8 @@
   /-\*- [Ii][Dd][Ll] -\*-/				idl;
   /-\*- [Pp][Ee][Rr][Ll] -\*-/				perl;
   /^#![ \t]*\/.*\/perl/					perl;
+  /-\*- [Rr][Uu][Bb][Yy] -\*-/				ruby;
+  /^#![ \t]*\/.*\/(env )?ruby/				ruby;
   /^From:/						mail;
   /^#![ \t]*(\/usr)?\/bin\/[ngmt]?awk/			awk;
   /^#![ \t]*(\/usr)?\/bin\/sh/				sh;
