# New ports collection makefile for:	vttest
# Date created:		2005-07-21
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	vttest
PORTVERSION=	2005.10.20
CATEGORIES=	sysutils
MASTER_SITES=	ftp://invisible-island.net/vttest/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}/${PORTVERSION}

MAINTAINER=	nivit@email.it
COMMENT=	A program to test "VT100-compatibility" of terminals

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}
MAKEFILE=	makefile

MAN1=		vttest.1
PLIST_FILES=	bin/vttest

.include <bsd.port.mk>
