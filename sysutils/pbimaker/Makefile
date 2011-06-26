# New ports collection makefile for:	pbimaker
# Date created:				June 23, 2011
# Whom:					Jesse
#
# $FreeBSD$
#

PORTNAME=	pbimaker
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/makeapbi/makeapbi/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A program to convert ports into PBI modules

LICENSE=	BSD
NO_COFIGURE=	yes

WRKSRC=	${WRKDIR}/PBIMaker
PLIST_FILES=	bin/pbimaker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
