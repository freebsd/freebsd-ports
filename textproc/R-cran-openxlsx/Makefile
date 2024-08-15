PORTNAME=	openxlsx
DISTVERSION=	4.2.6.1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read, Write and Edit XLSX Files
WWW=		https://github.com/awalker89/openxlsx

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-stringi>=0:textproc/R-cran-stringi
RUN_DEPENDS=	R-cran-zip>0:archivers/R-cran-zip \
		R-cran-Rcpp>0:devel/R-cran-Rcpp\
		R-cran-stringi>=0:textproc/R-cran-stringi
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
