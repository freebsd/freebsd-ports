# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dplyr
DISTVERSION=	0.8.5
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Grammar of Data Manipulation

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-assertthat>=0.2.0:math/R-cran-assertthat \
		R-cran-glue>=1.3.0:devel/R-cran-glue \
		R-cran-magrittr>=1.5:devel/R-cran-magrittr \
		R-cran-pkgconfig>0:devel/R-cran-pkgconfig \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-Rcpp>=1.0.1:devel/R-cran-Rcpp \
		R-cran-rlang>=0.4.0:devel/R-cran-rlang \
		R-cran-tibble>=2.0.0:devel/R-cran-tibble \
		R-cran-tidyselect>=0.2.5:devel/R-cran-tidyselect \
		R-cran-BH>0:devel/R-cran-BH \
		R-cran-plogr>=0.2.0:devel/R-cran-plogr
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
