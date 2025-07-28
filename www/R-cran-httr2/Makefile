PORTNAME=	httr2
DISTVERSION=	1.2.1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Tools for Working HTTP requests
WWW=		https://cran.r-project.org/package=httr2

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-cli>=3.0.0:devel/R-cran-cli \
		R-cran-curl>=6.4.0:ftp/R-cran-curl \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-R6>0:devel/R-cran-R6 \
		R-cran-rappdirs>0:devel/R-cran-rappdirs \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang \
		R-cran-vctrs>=0.6.3:devel/R-cran-vctrs \
		R-cran-withr>0:devel/R-cran-withr
TEST_DEPENDS=	R-cran-askpass>0:security/R-cran-askpass \
		R-cran-clipr>0:devel/R-cran-clipr \
		R-cran-covr>0:devel/R-cran-covr \
		R-cran-docopt>0:devel/R-cran-docopt \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-jose>0:www/R-cran-jose \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-later>=1.4.0:devel/R-cran-later \
		R-cran-promises>0:devel/R-cran-promises \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.1.8:devel/R-cran-testthat \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-webfakes>=1.4.0:devel/R-cran-webfakes \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist

.include <bsd.port.mk>
