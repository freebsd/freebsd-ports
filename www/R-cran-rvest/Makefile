# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvest
PORTVERSION=	0.3.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-xml2>0:${PORTSDIR}/textproc/R-cran-xml2 \
		R-cran-httr>=0.5:${PORTSDIR}/www/R-cran-httr \
		R-cran-selectr>0:${PORTSDIR}/www/R-cran-selectr \
		R-cran-magrittr>0:${PORTSDIR}/devel/R-cran-magrittr

USES=	cran:auto-plist

.include <bsd.port.mk>
