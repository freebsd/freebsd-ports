# New ports collection makefile for:	Linux-style colorized `ls'
# Version required:			3.12.0.2 (GNU fileutils 3.12)
# Date created:				06 January 1996
# Whom:					bmc@WillsCreek.COM
#
# $Id$
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
CATEGORIES+=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/ \
		ftp://ftp.cdrom.com/pub/linux/slackware_source/a/bin/

PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_SITES=	ftp://sunsite.unc.edu/pub/Linux/distributions/slackware/source/a/bin/ \
		ftp://ftp.cdrom.com/pub/linux/slackware_source/a/bin/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bmc@WillsCreek.COM

GNU_CONFIGURE=	yes

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/linuxls.1
	gzip -9nf ${PREFIX}/man/man1/dircolors.1
.endif

.include <bsd.port.mk>
