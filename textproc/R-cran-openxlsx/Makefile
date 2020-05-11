# $FreeBSD$

PORTNAME=	openxlsx
DISTVERSION=	4.1.5
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read, Write and Edit XLSX Files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr
RUN_DEPENDS=	R-cran-zip>0:archivers/R-cran-zip \
		R-cran-Rcpp>0:devel/R-cran-Rcpp
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr

USES=		cran:auto-plist,compiles

.include <bsd.port.mk>
