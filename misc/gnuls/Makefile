# New ports collection makefile for:	Linux-style colorized `ls'
# Version required:			3.12.0.2 (GNU fileutils 3.12)
# Date created:				06 January 1996
# Whom:					bmc@WillsCreek.COM
#
# $Id: Makefile,v 1.2 1996/11/11 05:49:44 obrien Exp $
#

DISTNAME=	fileutils-3.12
PKGNAME=	linuxls-3.12.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/ \
		ftp://ftp.cdrom.com/pub/linux/slackware_source/a/bin/

PATCHFILES=	color-ls-3.12.0.2.patch.gz
PATCH_SITES=	ftp://sunsite.unc.edu/pub/Linux/distributions/slackware/source/a/bin/ \
		ftp://ftp.cdrom.com/pub/linux/slackware_source/a/bin/

MAINTAINER=	bmc@WillsCreek.COM

PATCH_DIST_STRIP=	-p1
GNU_CONFIGURE=	yes
MAN1=		linuxls.1 dircolors.1

.include <bsd.port.mk>
