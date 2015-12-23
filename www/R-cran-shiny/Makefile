# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiny
PORTVERSION=	0.12.2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-httpuv>=1.3.3:${PORTSDIR}/www/R-cran-httpuv \
		R-cran-mime>=0.3:${PORTSDIR}/misc/R-cran-mime \
		R-cran-jsonlite>=0.9.16:${PORTSDIR}/converters/R-cran-jsonlite \
		R-cran-xtable>0:${PORTSDIR}/textproc/R-cran-xtable \
		R-cran-digest>0:${PORTSDIR}/security/R-cran-digest \
		R-cran-htmltools>=0.2.6:${PORTSDIR}/textproc/R-cran-htmltools \
		R-cran-R6>=2.0:${PORTSDIR}/devel/R-cran-R6

USES=	cran:auto-plist

.include <bsd.port.mk>
