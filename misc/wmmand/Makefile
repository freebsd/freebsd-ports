# New ports collection makefile for:	wmMand
# Date created:		16 April 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	wmmand
PORTVERSION=	1.0
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/
DISTNAME=	wmMand-${PORTVERSION}

MAINTAINER=	cpiazza@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/${DISTNAME}/wmMand

USE_GMAKE=	yes
USE_X_PREFIX=	yes
ALL_TARGET=	clean all

MAN1=		wmMand.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMand ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/wmMand.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
