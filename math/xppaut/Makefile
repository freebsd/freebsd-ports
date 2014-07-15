# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	xppaut
PORTVERSION=	7.0
PORTREVISION=	1
CATEGORIES=	math graphics
MASTER_SITES=	http://www.math.pitt.edu/~bard/bardware/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Graphical tool for solving differential equations, etc

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XORG=	xbitmaps x11 xproto
CFLAGS+=	-w -Wno-return-type
WRKSRC=		${WRKDIR}
ALL_TARGET=	xppaut

post-build:
	${RM} -f ${WRKSRC}/ode/._*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	NOPORTDOCS=yes
.endif
.if !${PORT_OPTIONS:MEXAMPLES}
MAKE_ENV+=	NOPORTEXAMPLES=yes
.endif

.include <bsd.port.mk>
