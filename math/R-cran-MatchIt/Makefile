# Created by: Wen Heping <wen@FreeBSD.org>

PORTNAME=	MatchIt
DISTVERSION=	4.2.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Nonparametric Preprocessing for Parametric Casual Inference

LICENSE=	GPLv2+

BUILD_DEPENDS=	R-cran-Matching>=0:math/R-cran-Matching \
		R-cran-rgenoud>=0:math/R-cran-rgenoud \
		R-cran-Rcpp>=0:devel/R-cran-Rcpp \
		R-cran-RcppProgress>=0:devel/R-cran-RcppProgress \
		R-cran-backports>=0:math/R-cran-backports
RUN_DEPENDS=	R-cran-Matching>=0:math/R-cran-Matching \
		R-cran-rgenoud>=0:math/R-cran-rgenoud\
		R-cran-Rcpp>=:devel/R-cran-Rcpp\
		R-cran-RcppProgress>=0:devel/R-cran-RcppProgress \
		R-cran-backports>=0:math/R-cran-backports

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
