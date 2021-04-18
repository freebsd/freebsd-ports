# Created by: Guangyuan Yang <ygy@FreeBSD.org>

PORTNAME=	gh
DISTVERSION=	1.2.1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	GitHub API for R

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-cli>=2.0.1:devel/R-cran-cli \
		R-cran-ini>0:devel/R-cran-ini \
		R-cran-gitcreds>0:security/R-cran-gitcreds \
		R-cran-httr>=1.2:www/R-cran-httr
TEST_DEPENDS=	R-cran-covr>0:devel/R-cran-covr \
		R-cran-rprojroot>0:devel/R-cran-rprojroot \
		R-cran-testthat>=2.3.2:devel/R-cran-testthat \
		R-cran-withr>0:devel/R-cran-withr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown

USES=		cran:auto-plist

.include <bsd.port.mk>
