# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spdep
DISTVERSION=	0.6-4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Spatial dependence: weighting schemes, statistics, and models

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-sp>=1.0:math/R-cran-sp \
		R-cran-LearnBayes>0:math/R-cran-LearnBayes \
		R-cran-deldir>0:math/R-cran-deldir \
		R-cran-coda>0:math/R-cran-coda \
		R-cran-gmodels>0:devel/R-cran-gmodels

USES=	cran:auto-plist

.include <bsd.port.mk>
