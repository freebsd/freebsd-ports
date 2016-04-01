# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiny
PORTVERSION=	0.13.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	R-cran-httpuv>=1.3.3:www/R-cran-httpuv \
		R-cran-mime>=0.3:misc/R-cran-mime \
		R-cran-jsonlite>=0.9.16:converters/R-cran-jsonlite \
		R-cran-xtable>0:textproc/R-cran-xtable \
		R-cran-digest>0:security/R-cran-digest \
		R-cran-htmltools>=0.3:textproc/R-cran-htmltools \
		R-cran-R6>=2.0:devel/R-cran-R6

USES=	cran:auto-plist

.include <bsd.port.mk>
