# New ports collection makefile for:	xorsearch
# Date created:				18 December 2007
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	xorsearch
PORTVERSION=	1.2.0
CATEGORIES=	security textproc
MASTER_SITES=	http://www.didierstevens.com/files/software/
DISTNAME=	XORSearch_V1_2_0

MAINTAINER=	edwin@mavetju.org
COMMENT=	Search for a given string in an XOR or ROL encoded binary file

USE_ZIP=	yes
WRKSRC=		${WRKDIR}

PLIST_FILES=	bin/xorsearch

do-build:
	${CC} -o ${WRKDIR}/XORSearch ${WRKDIR}/XORSearch.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/XORSearch ${PREFIX}/bin/xorsearch

.include <bsd.port.mk>
