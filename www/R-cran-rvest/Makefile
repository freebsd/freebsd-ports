# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rvest
PORTVERSION=	0.2.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Easily Harvest (Scrape) Web Pages

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-httr>=0.5:${PORTSDIR}/www/R-cran-httr \
		R-cran-XML>0:${PORTSDIR}/textproc/R-cran-XML \
		R-cran-selectr>0:${PORTSDIR}/www/R-cran-selectr \
		R-cran-magrittr>0:${PORTSDIR}/devel/R-cran-magrittr

USES=	cran:auto-plist

.include <bsd.port.mk>
