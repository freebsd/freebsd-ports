# New ports collection makefile for:    mkisofs
# Version required:     1.0.5
# Date created:         07 Aug 1996
# Whom:                 jkh
#
# $Id$
#

DISTNAME=       mkisofs-1.05
CATEGORIES+=	sysutils
MASTER_SITES=   ftp://ftp.cdrom.com/pub/linux/tsx-11/BETA/cdrom/

MAINTAINER=	jkh@FreeBSD.org

NO_WRKSUBDIR=   yes     
ALL_TARGET=

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure

post-install:
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man8/mkisofs.8
.endif

.include <bsd.port.mk>
