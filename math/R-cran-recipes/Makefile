# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	recipes
PORTVERSION=	0.1.16
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Preprocessing Tools to Create Design Matrices

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-generics>=0.1.0:devel/R-cran-generics \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-gower>0:math/R-cran-gower \
		R-cran-ipred>0:math/R-cran-ipred \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-lubridate>0:devel/R-cran-lubridate \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-purrr>=0.2.3:devel/R-cran-purrr \
		R-cran-rlang>=0.4.0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-tidyr>=1.0.0:devel/R-cran-tidyr \
		R-cran-tidyselect>=1.1.0:devel/R-cran-tidyselect \
		R-cran-timeDate>0:finance/R-cran-timeDate \
		R-cran-withr>0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
