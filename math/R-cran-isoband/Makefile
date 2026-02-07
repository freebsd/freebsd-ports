PORTNAME=	isoband
DISTVERSION=	0.3.0
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Generate Isolines and Isobands from Regularly Spaced Elevation Grids
WWW=		https://cran.r-project.org/web/packages/isoband/

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-cpp11>0:devel/R-cran-cpp11 \
		R-cran-rlang>0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-sf>0:math/R-cran-sf \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		compiler:c++17-lang cran:auto-plist,compiles

.include <bsd.port.mk>
