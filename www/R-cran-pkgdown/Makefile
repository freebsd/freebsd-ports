PORTNAME=	pkgdown
DISTVERSION=	2.2.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Generate an attractive and useful website from a source package
WWW=		https://cran.r-project.org/package=pkgdown

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-bslib>=0.5.4:www/R-cran-bslib \
		R-cran-callr>=3.7.3:devel/R-cran-callr \
		R-cran-cli>=3.6.1:devel/R-cran-cli \
		R-cran-desc>=1.4.0:devel/R-cran-desc \
		R-cran-downlit>=0.4.4:textproc/R-cran-downlit \
		R-cran-fontawesome>0:devel/R-cran-fontawesome \
		R-cran-fs>=1.4.0:filesystems/R-cran-fs \
		R-cran-httr2>=1.0.2:www/R-cran-httr2 \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-openssl>0:security/R-cran-openssl \
		R-cran-purrr>=1.0.0:devel/R-cran-purrr \
		R-cran-ragg>=1.4.0:graphics/R-cran-ragg \
		R-cran-rlang>=1.1.4:devel/R-cran-rlang \
		R-cran-rmarkdown>=2.27:textproc/R-cran-rmarkdown \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-whisker>0:devel/R-cran-whisker \
		R-cran-withr>=2.4.3:devel/R-cran-withr \
		R-cran-xml2>=1.3.1:textproc/R-cran-xml2 \
		R-cran-yaml>=2.3.9:textproc/R-cran-yaml
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-evaluate>=0.24.0:devel/R-cran-evaluate \
		R-cran-gert>0:devel/R-cran-gert \
		R-cran-htmltools>0:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-knitr>=1.50:print/R-cran-knitr \
		R-cran-magick>0:graphics/R-cran-magick \
		R-cran-pkgload>=1.0.2:devel/R-cran-pkgload \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-sass>0:textproc/R-cran-sass \
		R-cran-testthat>=3.1.3:devel/R-cran-testthat

USES=		cran:auto-plist

TESTING_UNSAFE=	Needed diffviewer gt, quarto, rsconnect, rticles CRAN packages

.include <bsd.port.mk>
