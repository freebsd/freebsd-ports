Source: https://webdav.seas.upenn.edu/viewvc/unison/branches/2.40/src/update.mli?view=patch&r1=435&r2=457&pathrev=457

--- update.mli.orig	2009-05-02 02:31:27 UTC
+++ update.mli
@@ -1,7 +1,7 @@
 (* Unison file synchronizer: src/update.mli *)
 (* Copyright 1999-2009, Benjamin C. Pierce (see COPYING for details) *)
 
-module NameMap : Map.S with type key = Name.t
+module NameMap : MyMap.S with type key = Name.t
 
 type archive =
     ArchiveDir of Props.t * archive NameMap.t
