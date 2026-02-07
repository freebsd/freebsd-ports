PORTNAME=	gtable
DISTVERSION=	0.3.6
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Arrange grobs in tables
WWW=		https://cran.r-project.org/web/packages/gtable/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-glue>0:devel/R-cran-glue \
		R-cran-lifecycle>0:devel/R-cran-lifecycle \
		R-cran-rlang>=1.1.0:devel/R-cran-rlang
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-ggplot2>0:graphics/R-cran-ggplot2 \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-profvis>0:devel/R-cran-profvis \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
