# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	recipes
PORTVERSION=	0.1.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Preprocessing Tools to Create Design Matrices

LICENSE=	GPLv2

CRAN_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-ipred>0:math/R-cran-ipred \
		R-cran-dimRed>=0.1.0:math/R-cran-dimRed \
		R-cran-lubridate>0:devel/R-cran-lubridate \
		R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-ddalpha>0:math/R-cran-ddalpha \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-rlang>=0.1.1:devel/R-cran-rlang \
		R-cran-gower>0:math/R-cran-gower \
		R-cran-RcppRoll>0:math/R-cran-RcppRoll \
		R-cran-tidyselect>=0.1.1:devel/R-cran-tidyselect \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
