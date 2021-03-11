# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvest
PORTVERSION=	1.0.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-httr>=0.5:www/R-cran-httr \
		R-cran-lifecycle>=1.0.0:devel/R-cran-lifecycle \
		R-cran-magrittr>0:devel/R-cran-magrittr \
		R-cran-rlang>=0.4.10:devel/R-cran-rlang \
		R-cran-selectr>0:www/R-cran-selectr \
		R-cran-tibble>0:devel/R-cran-tibble \
		R-cran-xml2>=1.3:textproc/R-cran-xml2
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
