# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httr
PORTVERSION=	1.0.0
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Tools for Working with URLs and HTTP

LICENSE=	MIT

RUN_DEPENDS=	R-cran-digest>0:${PORTSDIR}/security/R-cran-digest \
		R-cran-jsonlite>0:${PORTSDIR}/converters/R-cran-jsonlite \
		R-cran-mime>0:${PORTSDIR}/misc/R-cran-mime \
		R-cran-curl>=0.6:${PORTSDIR}/ftp/R-cran-curl \
		R-cran-R6>0:${PORTSDIR}/devel/R-cran-R6 \
		R-cran-stringr>=0.6.1:${PORTSDIR}/textproc/R-cran-stringr

USES=	cran:auto-plist

.include <bsd.port.mk>
