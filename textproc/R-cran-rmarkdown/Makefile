PORTNAME=	rmarkdown
DISTVERSION=	2.30
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Dynamic Documents for R
WWW=		https://cran.r-project.org/package=rmarkdown

LICENSE=	GPLv3

RUN_DEPENDS=	hs-pandoc>=1.14:textproc/hs-pandoc \
		R-cran-bslib>=0.2.5.1:www/R-cran-bslib \
		R-cran-evaluate>=0.13:devel/R-cran-evaluate \
		R-cran-fontawesome>=0.5.0:devel/R-cran-fontawesome \
		R-cran-htmltools>=0.5.1:textproc/R-cran-htmltools \
		R-cran-jquerylib>0:www/R-cran-jquerylib \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-knitr>=1.43:print/R-cran-knitr \
		R-cran-stringr>=1.2.0:textproc/R-cran-stringr \
		R-cran-tinytex>=0.31:print/R-cran-tinytex \
		R-cran-xfun>=0.36:misc/R-cran-xfun \
		R-cran-yaml>=2.1.19:textproc/R-cran-yaml
TEST_DEPENDS=	R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
