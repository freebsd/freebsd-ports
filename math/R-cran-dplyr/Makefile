# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dplyr
DISTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Grammar of Data Manipulation

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-BH>=1.69.0.1:devel/R-cran-BH \
		R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp \
		R-cran-bindrcpp>=0.2:devel/R-cran-bindrcpp \
		R-cran-glue>=1.3.1:devel/R-cran-glue \
		R-cran-pkgconfig>=2.0.2:devel/R-cran-pkgconfig \
		R-cran-R6>=2.4.0:devel/R-cran-R6 \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-plogr>=0.1.10:devel/R-cran-plogr \
		R-cran-tibble>=2.1.1:devel/R-cran-tibble \
		R-cran-assertthat>=0.2.1:math/R-cran-assertthat \
		R-cran-tidyselect>=0.2.5:devel/R-cran-tidyselect \
		R-cran-rlang>=0.3.4:devel/R-cran-rlang
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
