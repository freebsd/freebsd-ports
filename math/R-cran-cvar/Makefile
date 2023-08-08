PORTNAME=	cvar
DISTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Compute Expected Shortfall and Value at Risk for Continuous Distributions
WWW=		https://geobosh.github.io/cvar/

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-Rdpack>=0.8:devel/R-cran-Rdpack \
		R-cran-gbutils>0:math/R-cran-gbutils
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-PerformanceAnalytics>0:finance/R-cran-PerformanceAnalytics \
		R-cran-fGarch>0:finance/R-cran-fGarch

USES=		cran:auto-plist

.include <bsd.port.mk>
