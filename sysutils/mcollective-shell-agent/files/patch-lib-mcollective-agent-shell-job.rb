# $FreeBSD$
--- lib/mcollective/agent/shell/job.rb.orig	2014-08-14 12:52:06.644348698 +0200
+++ lib/mcollective/agent/shell/job.rb	2014-08-14 12:52:14.552664032 +0200
@@ -1,4 +1,5 @@
 require 'securerandom'
+require 'pathname'
 
 # The Job class manages the spawning and state tracking for a process as it's
 # running.
