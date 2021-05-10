PORTNAME=	forcats
DISTVERSION=	0.5.1
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Tools for Working with Categorical Variables (Factors)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-ellipsis>0:devel/R-cran-ellipsis \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-tibble>0:devel/R-cran-tibble
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist

.include <bsd.port.mk>
