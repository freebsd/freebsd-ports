PORTNAME=	reprex
DISTVERSION=	2.1.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Prepare Reproducible Example Code via the Clipboard
WWW=		https://cran.r-project.org/web/packages/reprex/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-callr>=3.6.0:devel/R-cran-callr \
		R-cran-cli>=3.2.0:devel/R-cran-cli \
		R-cran-clipr>=0.4.0:devel/R-cran-clipr \
		R-cran-fs>0:sysutils/R-cran-fs \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-knitr>=1.23:print/R-cran-knitr \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.0.0:devel/R-cran-rlang \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-withr>=2.3.0:devel/R-cran-withr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS} \
		hs-pandoc>=2.0:textproc/hs-pandoc
TEST_DEPENDS=	R-cran-testthat>=3.0.2:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
