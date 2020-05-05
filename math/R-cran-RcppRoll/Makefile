# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RcppRoll
DISTVERSION=	0.3.0
PORTREVISION=	3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Efficient Rolling / Windowed Operations

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>0:devel/R-cran-Rcpp
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
