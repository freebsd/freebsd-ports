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

USE_XORG=	x11 xbitmaps xproto
CFLAGS+=	-w -Wno-return-type
WRKSRC=		${WRKDIR}
ALL_TARGET=	xppaut

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_MAKE_ENV_OFF=	NOPORTDOCS=yes
EXAMPLES_MAKE_ENV_OFF=	NOPORTEXAMPLES=yes

post-build:
	${RM} ${WRKSRC}/ode/._*

.include <bsd.port.mk>
