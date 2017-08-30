# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiny
PORTVERSION=	1.0.5
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-httpuv>=1.3.5:www/R-cran-httpuv \
		R-cran-mime>=0.3:misc/R-cran-mime \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-xtable>0:textproc/R-cran-xtable \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-htmltools>=0.3.5:textproc/R-cran-htmltools \
		R-cran-R6>=2.0:devel/R-cran-R6 \
		R-cran-sourcetools>0:devel/R-cran-sourcetools
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
