PORTNAME=	htmlTable
DISTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Advanced tables for Markdown/HTML
WWW=		https://cran.r-project.org/web/packages/htmlTable/

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-stringr>0:textproc/R-cran-stringr \
		R-cran-knitr>0:print/R-cran-knitr \
		R-cran-htmlwidgets>0:www/R-cran-htmlwidgets \
		R-cran-rstudioapi>0:devel/R-cran-rstudioapi \
		R-cran-checkmate>0:devel/R-cran-checkmate
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
