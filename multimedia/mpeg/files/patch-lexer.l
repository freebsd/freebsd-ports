--- lexer.l.orig	Mon Jun  3 18:16:25 2002
+++ lexer.l	Mon Jun  3 18:16:32 2002
@@ -1,3 +1,4 @@
+%{
 /*************************************************************
 Copyright (C) 1990, 1991, 1993 Andy C. Hung, all rights reserved.
 PUBLIC DOMAIN LICENSE: Stanford University Portable Video Research
@@ -15,7 +16,6 @@
 Video Research Group (PVRG) code, and not by any author(s) (or
 Stanford University) name.
 *************************************************************/
-%{
 
 /*LABEL lexer.c */
 
