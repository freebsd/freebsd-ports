# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	twitteR
PORTVERSION=	1.1.9
PORTREVISION=	4
CATEGORIES=	net
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	R based Twitter client

LICENSE=	ART20

RUN_DEPENDS=	R-cran-bit64>0:devel/R-cran-bit64 \
		R-cran-rjson>0:converters/R-cran-rjson \
		R-cran-DBI>=0.3.1:databases/R-cran-DBI \
		R-cran-httr>=1.0.0:www/R-cran-httr

USES=	cran:auto-plist

.include <bsd.port.mk>
