# New ports collection makefile for:   wmCalClock
# Date created:        16 March 1999
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmCalClock
PORTVERSION= 	1.25
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://nis-www.lanl.gov/~mgh/WindowMaker/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm/

WRKSRC=		${WRKDIR}/${DISTNAME}/Src

USE_X_PREFIX=	yes
USE_GMAKE=	yes

ALL_TARGET=	clean all

MAN1=		wmCalClock.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/wmCalClock.1 ${PREFIX}/man/man1/
	${INSTALL_PROGRAM} ${WRKSRC}/wmCalClock ${PREFIX}/bin/

.include <bsd.port.mk>
