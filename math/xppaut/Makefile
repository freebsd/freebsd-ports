# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	xppaut
PORTVERSION=	7.0
PORTREVISION=	3
CATEGORIES=	math graphics
MASTER_SITES=	http://www.math.pitt.edu/~bard/bardware/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Graphical tool for solving differential equations, etc

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11 xbitmaps xorgproto
CFLAGS+=	-w -Wno-return-type
ALL_TARGET=	xppaut

NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_MAKE_ENV_OFF=	NOPORTDOCS=yes
EXAMPLES_MAKE_ENV_OFF=	NOPORTEXAMPLES=yes

post-build:
	${RM} ${WRKSRC}/ode/._*

.include <bsd.port.mk>
