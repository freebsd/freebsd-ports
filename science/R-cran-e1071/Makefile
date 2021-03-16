# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e1071
DISTVERSION=	1.7-5
CATEGORIES=	science
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Misc Functions of the Department of Statistics (e1071), TU Wien

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-proxy>0:math/R-cran-proxy
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
