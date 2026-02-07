PORTNAME=	htmltools
DISTVERSION=	0.5.9
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Tools for HTML generation and output
WWW=		https://cran.r-project.org/package=htmltools

LICENSE=	GPLv2+

CRAN_DEPENDS=	R-cran-base64enc>0:converters/R-cran-base64enc \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-fastmap>=1.1.0:databases/R-cran-fastmap \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-markdown>0:textproc/R-cran-markdown \
		R-cran-ragg>0:graphics/R-cran-ragg \
		R-cran-shiny>0:www/R-cran-shiny \
		R-cran-testthat>0:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
