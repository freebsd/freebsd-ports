Replied: Sat, 14 Apr 2001 17:12:38 -0700
Return-Path: steve@havk.org
Delivery-Date: Sat Apr 14 15:52:07 2001
Received: from localhost (bmah@localhost [::1])
	by bmah-freebsd-0.cisco.com (8.11.3/8.11.1) with ESMTP id f3EMq7G38353
	for <bmah@localhost>; Sat, 14 Apr 2001 15:52:07 -0700 (PDT)
	(envelope-from steve@havk.org)
Received: from mira-sjcm-2.cisco.com [171.69.43.98]
	by localhost with IMAP (fetchmail-5.7.6)
	for bmah@localhost (single-drop); Sat, 14 Apr 2001 15:52:07 -0700 (PDT)
Received: from sj-msg-core-1.cisco.com (sj-msg-core-1.cisco.com [171.71.163.11])
	by mira-sjcm-2.cisco.com (Mirapoint)
	with ESMTP id AFL02076;
	Sat, 14 Apr 2001 15:51:45 -0700 (PDT)
Received: from sj-msg-av-1.cisco.com (sj-msg-av-1.cisco.com [171.69.11.130])
	by sj-msg-core-1.cisco.com (8.9.3/8.9.1) with ESMTP id PAA18471
	for <bmah@sj-av.cisco.com>; Sat, 14 Apr 2001 15:51:45 -0700 (PDT)
Received: from proxy1.cisco.com (localhost [127.0.0.1])
	by sj-msg-av-1.cisco.com (8.10.1/8.10.1) with ESMTP id f3EMpmf07582
	for <bmah@sj-av.cisco.com>; Sat, 14 Apr 2001 15:51:48 -0700 (PDT)
Received: from mx2.freebsd.org (mx2.freebsd.org [216.136.204.119])
	by proxy1.cisco.com (8.11.2/8.11.2) with ESMTP id f3EMltH14811
	for <bmah@cisco.com>; Sat, 14 Apr 2001 15:47:55 -0700 (PDT)
Received: from hub.freebsd.org (hub.freebsd.org [216.136.204.18])
	by mx2.freebsd.org (Postfix) with ESMTP id 4D41C55875
	for <bmah@cisco.com>; Sat, 14 Apr 2001 15:47:56 -0700 (PDT)
	(envelope-from steve@havk.org)
Received: by hub.freebsd.org (Postfix)
	id C240537B5AF; Sat, 14 Apr 2001 15:47:57 -0700 (PDT)
Delivered-To: bmah@freebsd.org
Received: from mail.hiwaay.net (fly.HiWAAY.net [208.147.154.56])
	by hub.freebsd.org (Postfix) with ESMTP id 3BCCB37B43F
	for <bmah@freebsd.org>; Sat, 14 Apr 2001 15:47:57 -0700 (PDT)
	(envelope-from steve@havk.org)
Received: from bsd.havk.org (user-24-214-88-8.knology.net [24.214.88.8])
	by mail.hiwaay.net (8.11.3/8.11.3) with ESMTP id f3EMlt504060
	for <bmah@freebsd.org>; Sat, 14 Apr 2001 17:47:55 -0500 (CDT)
Received: by bsd.havk.org (Postfix, from userid 1001)
	id 5E0171A7D3; Sat, 14 Apr 2001 17:47:53 -0500 (CDT)
Date: Sat, 14 Apr 2001 17:47:53 -0500
From: Steve Price <steve@freebsd.org>
To: bmah@freebsd.org
Subject: pchar port
Message-ID: <20010414174753.B58358@bsd.havk.org>
Mime-Version: 1.0
Content-Type: text/plain; charset=us-ascii
Content-Disposition: inline
User-Agent: Mutt/1.2.5i
X-Operating-System: FreeBSD 4.2-STABLE i386

Bruce,

I just noticed that beta is having a problem building the latest
pchar port.  The following patch fixed it for me.  For more information
on the error see this URL.

        http://beta.freebsd.org/errorlogs/4-latest/pchar-1.3.2.log

Thanks.

-steve

--- main.cc.orig	Sat Apr 14 17:38:32 2001
+++ main.cc	Sat Apr 14 17:39:16 2001
@@ -1412,8 +1412,8 @@
 	    fprintf(stdout, "    End of path not reached after %d hops\n", pathLength);
 	}
 
-	fprintf(stdout, "    Start time:        %s", ctime(&(timeFirst.tv_sec)));
-	fprintf(stdout, "    End time:          %s", ctime(&(timeLast.tv_sec)));
+	fprintf(stdout, "    Start time:        %s", ctime((const time_t *)&(timeFirst.tv_sec)));
+	fprintf(stdout, "    End time:          %s", ctime((const time_t *)&(timeLast.tv_sec)));
     }
 
     //
