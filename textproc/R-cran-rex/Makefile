PORTNAME=	rex
DISTVERSION=	1.2.2
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Friendly Regular Expressions
WWW=		https://cran.r-project.org/package=rex

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-dplyr>0:math/R-cran-dplyr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-Hmisc>0:devel/R-cran-Hmisc \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-roxygen2>0:devel/R-cran-roxygen2 \
		R-cran-rvest>0:www/R-cran-rvest \
		R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
