# $FreeBSD$

PORTNAME=	forcats
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Tools for Working with Categorical Variables (Factors)

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble
TEST_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2

USES=		cran:auto-plist

.include <bsd.port.mk>
