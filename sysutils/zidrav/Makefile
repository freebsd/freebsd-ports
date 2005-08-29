# New ports collection makefile for:   zidrav
# Date created:        14 July 2003
# Whom:                Cosmin Stroe <cstroe1@uic.edu>
#
# $FreeBSD$
#

PORTNAME=	zidrav
PORTVERSION=	1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	zidrav4unix-${PORTVERSION}

MAINTAINER=	cstroe1@uic.edu
COMMENT=	A file corruption detection and repair program

ALL_TARGET=	zidrav
MAN1=		zidrav.1
PLIST_FILES=	bin/zidrav

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zidrav ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zidrav.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
