# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httr
PORTVERSION=	1.2.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Working with URLs and HTTP

LICENSE=	MIT

RUN_DEPENDS=	R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-curl>=0.9.1:ftp/R-cran-curl \
		R-cran-openssl>=0.8:security/R-cran-openssl \
		R-cran-R6>0:devel/R-cran-R6

USES=	cran:auto-plist

.include <bsd.port.mk>
