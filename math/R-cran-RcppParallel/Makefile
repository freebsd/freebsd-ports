PORTNAME=	RcppParallel
DISTVERSION=	5.1.11-2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	chris.longros@gmail.com
COMMENT=	Parallel programming tools for Rcpp
WWW=		https://rcppcore.github.io/RcppParallel/

LICENSE=	GPLv3

LIB_DEPENDS=	libtbb.so:devel/onetbb
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-Rcpp>0:devel/R-cran-Rcpp \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-RUnit>0:devel/R-cran-RUnit

USES=		cran:auto-plist,compiles gmake localbase

CONFIGURE_ENV=	TBB_LIB=${LOCALBASE}/lib \
		TBB_INC=${LOCALBASE}/include
MAKE_ENV=	TBB_LIB=${LOCALBASE}/lib \
		TBB_INC=${LOCALBASE}/include

.include <bsd.port.mk>
