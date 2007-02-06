# New ports collection makefile for: ffs2recov
# Date created:         20070204
# Whom:                 sten@blinkenlights.nl
#
# $FreeBSD$
#

PORTNAME=	ffs2recov
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.exit.com/Archives/FreeBSD/

MAINTAINER=	sten@blinkenlights.nl
COMMENT=	A utility to recover UFS2 filesystems

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN8=		ffs2recov.8
PLIST_FILES=	sbin/ffs2recov

MAKE_ENV=	BINDIR=${PREFIX}/sbin MANDIR=${MANPREFIX}/man/man

.include <bsd.port.mk>
