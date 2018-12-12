# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dplyr
DISTVERSION=	0.7.8
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Grammar of Data Manipulation

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-Rcpp>=0.12.0:devel/R-cran-Rcpp \
		R-cran-bindrcpp>=0.2:devel/R-cran-bindrcpp \
		R-cran-glue>=1.1.1:devel/R-cran-glue \
		R-cran-pkgconfig>=0:devel/R-cran-pkgconfig \
		R-cran-plogr>=0:devel/R-cran-plogr \
		R-cran-BH>=1.58.0.1:devel/R-cran-BH \
		R-cran-R6>=0:devel/R-cran-R6 \
		R-cran-DBI>=0.3:databases/R-cran-DBI \
		R-cran-magrittr>=0:devel/R-cran-magrittr \
		R-cran-lazyeval>=0.1.10:math/R-cran-lazyeval \
		R-cran-tibble>=1.3.1:devel/R-cran-tibble \
		R-cran-assertthat>=0:math/R-cran-assertthat \
		R-cran-tidyselect>=0:devel/R-cran-tidyselect
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
