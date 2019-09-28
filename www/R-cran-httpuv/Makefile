# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpuv
PORTVERSION=	1.5.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	HTTP and WebSocket server library for R

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-promises>0:devel/R-cran-promises \
		R-cran-later>=0.8.0:devel/R-cran-later \
		R-cran-BH>0:devel/R-cran-BH
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
