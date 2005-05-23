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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DockApp mandelbrot explorer

PLIST_FILES=	bin/wmMand
WRKSRC=		${WRKDIR}/${DISTNAME}/wmMand

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
ALL_TARGET=	clean all
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		INCDIR=-I${X11BASE}/include LIBDIR=-L${X11BASE}/lib

MAN1=		wmMand.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmMand ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmMand.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
