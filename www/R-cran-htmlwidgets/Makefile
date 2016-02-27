# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmlwidgets
PORTVERSION=	0.6
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	HTML Widgets for R

LICENSE=	MIT

RUN_DEPENDS=	R-cran-htmltools>=0.3:${PORTSDIR}/textproc/R-cran-htmltools \
		R-cran-jsonlite>=0.9.16:${PORTSDIR}/converters/R-cran-jsonlite \
		R-cran-yaml>0:${PORTSDIR}/textproc/R-cran-yaml

USES=	cran:auto-plist

.include <bsd.port.mk>
