# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DT
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	textproc
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Wrapper of the JavaScript Library 'DataTables'

LICENSE=	GPLv3

CRAN_DEPENDS=	R-cran-htmltools>=0.3.5:textproc/R-cran-htmltools \
		R-cran-htmlwidgets>=0.6:www/R-cran-htmlwidgets \
		R-cran-magrittr>0:devel/R-cran-magrittr
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
