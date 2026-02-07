PORTNAME=	Rsolnp
DISTVERSION=	2.0.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	General Non-Linear Optimization
WWW=		https://cran.r-project.org/web/packages/Rsolnp/

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-future.apply>0:devel/R-cran-future.apply \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-RcppArmadillo>0:math/R-cran-RcppArmadillo \
		R-cran-truncnorm>0:math/R-cran-truncnorm

BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
