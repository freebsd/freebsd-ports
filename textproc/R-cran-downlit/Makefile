PORTNAME=	downlit
DISTVERSION=	0.4.4
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Syntax Highlighting and Automatic Linking
WWW=		https://cran.r-project.org/web/packages/downlit/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-brio>0:devel/R-cran-brio \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-evaluate>0:devel/R-cran-evaluate \
		R-cran-fansi>0:devel/R-cran-fansi \
		R-cran-memoise>0:devel/R-cran-memoise \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-vctrs>0:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-yaml>0:textproc/R-cran-yaml
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-pkgload>0:devel/R-cran-pkgload \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-tidyverse>0:devel/R-cran-tidyverse \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist

.include <bsd.port.mk>
