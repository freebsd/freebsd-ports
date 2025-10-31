PORTNAME=	lava
DISTVERSION=	1.8.2
CATEGORIES=	math
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Latent Variable Models
WWW=		https://cran.r-project.org/package=lava

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-cli>0:devel/R-cran-cli \
		R-cran-future.apply>0:devel/R-cran-future.apply \
		R-cran-numDeriv>0:math/R-cran-numDeriv \
		R-cran-progressr>0:devel/R-cran-progressr \
		R-cran-SQUAREM>0:math/R-cran-SQUAREM
TEST_DEPENDS=	R-cran-geepack>0:math/R-cran-geepack \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-testthat>0:devel/R-cran-testthat

USES=		cran:auto-plist

.include <bsd.port.mk>
