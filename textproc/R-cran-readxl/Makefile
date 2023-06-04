PORTNAME=	readxl
DISTVERSION=	1.4.2
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Read Excel Files
WWW=		https://readxl.tidyverse.org

LICENSE=	MIT

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-cpp11>=0.4.0:devel/R-cran-cpp11 \
		R-cran-progress>0:devel/R-cran-progress
RUN_DEPENDS=	R-cran-cpp11>=0.4.0:devel/R-cran-cpp11 \
		R-cran-tibble>=2.0.1:devel/R-cran-tibble \
		R-cran-cellranger>0:textproc/R-cran-cellranger \
		R-cran-progress>0:devel/R-cran-progress
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-rprojroot>=1.1:devel/R-cran-rprojroot \
		R-cran-testthat>=3.1.6:devel/R-cran-testthat \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
