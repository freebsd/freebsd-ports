# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvest
PORTVERSION=	0.3.5
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-xml2>0:textproc/R-cran-xml2 \
		R-cran-httr>=0.5:www/R-cran-httr \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-selectr>0:www/R-cran-selectr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
