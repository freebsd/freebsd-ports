PORTNAME=	mpoly
DISTVERSION=	1.1.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Symbolic computing with multivariate polynomials in R
WWW=		https://cran.r-project.org/package=${PORTNAME}

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-orthopolynom>0:math/R-cran-orthopolynom \
		R-cran-partitions>0:math/R-cran-partitions \
		R-cran-plyr>0:devel/R-cran-plyr \
		R-cran-polynom>0:math/R-cran-polynom \
		R-cran-stringi>0:textproc/R-cran-stringi \
		R-cran-stringr>=1.0.0:textproc/R-cran-stringr \
		R-cran-tidyr>0:devel/R-cran-tidyr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-testthat>=2.1.0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
