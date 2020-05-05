# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiny
PORTVERSION=	1.4.0.2
PORTREVISION=	1
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

CRAN_DEPENDS=	R-cran-httpuv>=1.5.2:www/R-cran-httpuv \
		R-cran-mime>=0.3:misc/R-cran-mime \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-xtable>0:textproc/R-cran-xtable \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-htmltools>=0.4.0:textproc/R-cran-htmltools \
		R-cran-R6>=2.0:devel/R-cran-R6 \
		R-cran-sourcetools>0:devel/R-cran-sourcetools \
		R-cran-later>=1.0.0:devel/R-cran-later \
		R-cran-promises>=1.1.0:devel/R-cran-promises \
		R-cran-crayon>0:devel/R-cran-crayon \
		R-cran-rlang>=0.4.0:devel/R-cran-rlang \
		R-cran-fastmap>=1.0.0:databases/R-cran-fastmap
BUILD_DEPENDS=	${CRAN_DEPENDS}
RUN_DEPENDS=	${CRAN_DEPENDS}

USES=	cran:auto-plist

.include <bsd.port.mk>
