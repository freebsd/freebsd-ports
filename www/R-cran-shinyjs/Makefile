PORTNAME=	shinyjs
DISTVERSION=	2.1.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Easily Improve the User Experience of Your Shiny Apps in Seconds
WWW=		https://deanattali.com/shinyjs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-digest>=0.6.8:security/R-cran-digest \
		R-cran-shiny>=1.0.0:www/R-cran-shiny
TEST_DEPENDS=	R-cran-testthat>=0.9.1:devel/R-cran-testthat \
		R-cran-knitr>=1.7:print/R-cran-knitr \
		R-cran-htmltools>=0.2.9:textproc/R-cran-htmltools \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
