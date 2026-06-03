PORTNAME=	cvar
DISTVERSION=	0.6
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Compute Expected Shortfall and Value at Risk for Continuous Distributions
WWW=		https://cran.r-project.org/package=cvar

LICENSE=	GPLv2+

RUN_DEPENDS=	R-cran-gbutils>0:math/R-cran-gbutils \
		R-cran-Rdpack>=0.8:devel/R-cran-Rdpack
TEST_DEPENDS=	R-cran-fGarch>0:finance/R-cran-fGarch \
		R-cran-PerformanceAnalytics>0:finance/R-cran-PerformanceAnalytics \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
