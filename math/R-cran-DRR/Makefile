# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DRR
PORTVERSION=	0.0.4
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Dimensionality Reduction via Regression

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-kernlab>0:science/R-cran-kernlab \
		R-cran-CVST>0:math/R-cran-CVST
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
