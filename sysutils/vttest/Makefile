# New ports collection makefile for:	vttest
# Date created:		2005-07-21
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	vttest
PORTVERSION=	2005.01.07
CATEGORIES=	sysutils
MASTER_SITES=	ftp://invisible-island.net/vttest/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A program to test "VT100-compatibility" of terminals

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/vttest

MAN1=	vttest.1

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

MAKEFILE=	makefile

.include <bsd.port.mk>
