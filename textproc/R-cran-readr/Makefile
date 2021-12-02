# Created by: TAKATSU Tomonari <tota@FreeBSD.org>

PORTNAME=	readr
PORTVERSION=	2.1.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Read Rectangular Text Data

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-hms>=0.4.1:devel/R-cran-hms \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-vroom>=1.5.6:textproc/R-cran-vroom \
		R-cran-lifecycle>=0.2.0:devel/R-cran-lifecycle \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-tzdb>=0.1.1:devel/R-cran-tzdb
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		compiler:c++11-lang cran:auto-plist,compiles

.include <bsd.port.mk>
