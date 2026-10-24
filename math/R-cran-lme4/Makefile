PORTNAME=	lme4
DISTVERSION=	2.1-0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Linear mixed-effects models using Eigen and S4
WWW=		https://cran.r-project.org/package=lme4

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.note

RUN_DEPENDS=	R-cran-minqa>=1.1.15:math/R-cran-minqa \
		R-cran-nloptr>=1.0.4:math/R-cran-nloptr \
		R-cran-Rcpp>=1.1.1.1.1:devel/R-cran-Rcpp \
		R-cran-RcppEigen>=0.3.3.9.4:math/R-cran-RcppEigen \
		R-cran-reformulas>=0.4.3.1:math/R-cran-reformulas \
		R-cran-rlang>0:devel/R-cran-rlang
TEST_DEPENDS=	R-cran-car>0:math/R-cran-car \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-gridExtra>0:graphics/R-cran-gridExtra \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-optimx>0:misc/R-cran-optimx \
		R-cran-statmod>0:math/R-cran-statmod \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist,compiles

pre-test:

# Test depends not ported yet
.for pkg in DHARMa gamm4 glmmTMB mlmRev performance see
	@${LOCALBASE}/bin/Rscript -e 'install.packages("${pkg}", \
		repos = "https://cloud.r-project.org")'
.endfor

.include <bsd.port.mk>
