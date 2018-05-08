# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddalpha
PORTVERSION=	1.3.3
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Depth-Based Classification and Calculation of Data Depth

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-robustbase>0:math/R-cran-robustbase \
		R-cran-sfsmisc>0:devel/R-cran-sfsmisc \
		R-cran-geometry>0:math/R-cran-geometry \
		R-cran-Rcpp>=0.11.0:devel/R-cran-Rcpp \
		R-cran-BH>0:devel/R-cran-BH
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
