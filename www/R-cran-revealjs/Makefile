PORTNAME=	revealjs
DISTVERSION=	0.10.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	R Markdown Format for 'reveal.js' Presentations
WWW=		https://cran.r-project.org/package=${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-rmarkdown>=1.7:textproc/R-cran-rmarkdown
TEST_DEPENDS=	R-cran-bslib>0:www/R-cran-bslib \
		R-cran-testthat>=3.0.0:devel/R-cran-testthat \
		R-cran-withr>=2.4.2:devel/R-cran-withr \
		R-cran-xfun>0.21:misc/R-cran-xfun \
		R-cran-xml2>0:textproc/R-cran-xml2

USES=		cran:auto-plist

.include <bsd.port.mk>
