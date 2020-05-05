# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httr
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Working with URLs and HTTP

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-curl>=3.0.0:ftp/R-cran-curl \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-mime>0:misc/R-cran-mime \
		R-cran-openssl>=0.8:security/R-cran-openssl \
		R-cran-R6>0:devel/R-cran-R6
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
