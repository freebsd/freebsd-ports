--- src/cmd/ksh93/sh/jobs.c.orig	2010-12-02 00:57:47.000000000 +0800
+++ src/cmd/ksh93/sh/jobs.c	2011-10-05 10:52:30.844946545 +0800
@@ -945,6 +945,7 @@
 			if(!(pw = job_bypid(pid)))
 			{
 				pw = &dummy;
+				pw->p_shp = sh_getinterp();
 				pw->p_pid = pid;
 				pw->p_pgrp = pid;
 			}
