# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	crosstalk
PORTVERSION=	1.1.0.1
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Inter-Widget Interactivity for HTML Widgets

LICENSE=	MIT

CRAN_DEPENDS=	R-cran-htmltools>=0.3.6:textproc/R-cran-htmltools \
		R-cran-jsonlite>0:converters/R-cran-jsonlite \
		R-cran-lazyeval>0:math/R-cran-lazyeval \
		R-cran-R6>0:devel/R-cran-R6
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=		cran:auto-plist

.include <bsd.port.mk>
