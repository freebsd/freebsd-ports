# Created by: Guangyuan Yang <ygy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webshot
DISTVERSION=	0.5.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Take Screenshots of Web Pages

LICENSE=	GPLv2

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-callr>0:devel/R-cran-callr \
		R-cran-magrittr>0:devel/R-cran-magrittr
TEST_DEPENDS=	R-cran-knitr>0:print/R-cran-knitr \
		R-cran-rmarkdown>0:textproc/R-cran-rmarkdown \
		R-cran-httpuv>0:www/R-cran-httpuv \
		R-cran-shiny>0:www/R-cran-shiny

USES=		cran:auto-plist

.include <bsd.port.mk>
