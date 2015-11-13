--- SOPE/NGCards/iCalPerson.m.orig	2015-09-16 18:41:36 UTC
+++ SOPE/NGCards/iCalPerson.m
@@ -256,7 +256,7 @@
 - (BOOL)isEqual:(id)_other {
   if(_other == nil)
     return NO;
-  if([_other class] != self->isa)
+  if([_other class] != object_getClass(self))
     return NO;
   if([_other hash] != [self hash])
     return NO;
