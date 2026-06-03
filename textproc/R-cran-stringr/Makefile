PORTNAME=	stringr
DISTVERSION=	1.6.0
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Make it easier to work with strings
WWW=		https://cran.r-project.org/package=stringr

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>=1.6.1:devel/R-cran-glue \
		R-cran-lifecycle>=1.0.3:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-stringi>=1.5.3:textproc/R-cran-stringi \
		R-cran-vctrs>=0.4.0:devel/R-cran-vctrs
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble

USES=		cran:auto-plist

TESTING_UNSAFE=	Requires gt package from CRAN.

.include <bsd.port.mk>
