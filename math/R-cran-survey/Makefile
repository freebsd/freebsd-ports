PORTNAME=	survey
DISTVERSION=	4.4-8
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Analysis of complex survey samples
WWW=		https://r-survey.r-forge.r-project.org/survey/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

CRAN_DEPENDS=	R-cran-minqa>=1.1.15:math/R-cran-minqa \
		R-cran-numDeriv>=0:math/R-cran-numDeriv \
		R-cran-mitools>=2.4:math/R-cran-mitools \
		R-cran-RcppArmadillo>=0:math/R-cran-RcppArmadillo
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

NO_ARCH_IGNORE=	survey.so

.include <bsd.port.mk>
