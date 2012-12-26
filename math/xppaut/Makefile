# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	xppaut
PORTVERSION=	7.0
CATEGORIES=	math graphics
MASTER_SITES=	http://www.math.pitt.edu/~bard/bardware/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Graphical tool for solving differential equations, etc

MAN1=		xppaut.1
USE_XORG=	xbitmaps x11 xproto
CFLAGS+=	-w -Wno-return-type
WRKSRC=		${WRKDIR}
ALL_TARGET=	xppaut

.ifdef NOPORTDOCS
MAKE_ENV+=	NOPORTDOCS=yes
.endif
.ifdef NOPORTEXAMPLES
MAKE_ENV+=	NOPORTEXAMPLES=yes
.endif

.include <bsd.port.mk>
