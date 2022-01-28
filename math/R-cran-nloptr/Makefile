# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	nloptr
PORTVERSION=	2.0.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R interface to NLopt

LICENSE=	LGPL3

LIB_DEPENDS=	libnlopt.so:math/nlopt
RUN_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles pkgconfig

.include <bsd.port.mk>
