PORTNAME=	MCMCpack
DISTVERSION=	1.7-1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Markov chain Monte Carlo Package
WWW=		https://cran.r-project.org/web/packages/MCMCpack/

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-coda>=0.11.3:math/R-cran-coda \
		R-cran-mcmc>0:math/R-cran-mcmc \
		R-cran-quantreg>0:math/R-cran-quantreg

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
