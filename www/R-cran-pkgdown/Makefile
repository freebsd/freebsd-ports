PORTNAME=	pkgdown
DISTVERSION=	2.1.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Generate an attractive and useful website from a source package
WWW=		https://cran.r-project.org/web/packages/pkgdown/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-bslib>0:www/R-cran-bslib \
		R-cran-callr>0:devel/R-cran-callr \
		R-cran-cli>0:devel/R-cran-cli \
		R-cran-desc>0:devel/R-cran-desc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-downlit>0:textproc/R-cran-downlit \
		R-cran-fontawesome>0:devel/R-cran-fontawesome \
		R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-httr2>0:www/R-cran-httr2 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-purrr>0:devel/R-cran-purrr \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-rlang>0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-whisker>0:devel/R-cran-whisker \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-yaml>0:textproc/R-cran-yaml
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
