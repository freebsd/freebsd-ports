PORTNAME=	MatchIt
DISTVERSION=	4.7.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Nonparametric Preprocessing for Parametric Casual Inference
WWW=		https://gking.harvard.edu/matchit

LICENSE=	GPLv2+

BUILD_DEPENDS=	R-cran-Matching>=0:math/R-cran-Matching \
		R-cran-rgenoud>=0:math/R-cran-rgenoud \
		R-cran-Rcpp>=1.0.10:devel/R-cran-Rcpp \
		R-cran-RcppProgress>=0:devel/R-cran-RcppProgress \
		R-cran-backports>=0:math/R-cran-backports \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-chk>=0:devel/R-cran-chk
RUN_DEPENDS=	R-cran-Matching>=0:math/R-cran-Matching \
		R-cran-rgenoud>=0:math/R-cran-rgenoud\
		R-cran-Rcpp>=:devel/R-cran-Rcpp\
		R-cran-RcppProgress>=0:devel/R-cran-RcppProgress \
		R-cran-backports>=0:math/R-cran-backports

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
