# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nloptr
PORTVERSION=	1.0.4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R interface to NLopt

LICENSE=	LGPL3

LIB_DEPENDS=	libnlopt.so:math/nlopt

USES=	cran:auto-plist pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's/<<</</' ${WRKSRC}/configure

.include <bsd.port.mk>
