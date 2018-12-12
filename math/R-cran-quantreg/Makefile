# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quantreg
PORTVERSION=	5.36
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Quantile Regression

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-SparseM>0:math/R-cran-SparseM \
		R-cran-MatrixModels>0:math/R-cran-MatrixModels
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist,compiles

.include <bsd.port.mk>
