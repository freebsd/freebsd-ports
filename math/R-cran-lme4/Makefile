PORTNAME=	lme4
DISTVERSION=	1.1-38
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Linear mixed-effects models using Eigen and S4
WWW=		https://cran.r-project.org/package=lme4

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.note

CRAN_DEPENDS=	R-cran-minqa>=1.1.15:math/R-cran-minqa \
		R-cran-nloptr>=1.0.4:math/R-cran-nloptr \
		R-cran-Rcpp>=0.10.5:devel/R-cran-Rcpp \
		R-cran-RcppEigen>=0.3.3.9.4:math/R-cran-RcppEigen \
		R-cran-reformulas>=0.3.0:math/R-cran-reformulas \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-optimx>0:misc/R-cran-optimx \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

pre-test:
# R-cran-gamm4 package does not exist yet
	@${LOCALBASE}/bin/Rscript -e 'install.packages("gamm4", \
		repos = "https://cloud.r-project.org")'

.include <bsd.port.mk>
