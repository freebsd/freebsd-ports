# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	shiny
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	www
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Web Application Framework for R

LICENSE=	GPLv3

RUN_DEPENDS=	R-cran-httpuv>=1.1.0:${PORTSDIR}/www/R-cran-httpuv \
		R-cran-caTools>0:${PORTSDIR}/devel/R-cran-caTools \
		R-cran-RJSONIO>0:${PORTSDIR}/converters/R-cran-RJSONIO \
		R-cran-xtable>0:${PORTSDIR}/textproc/R-cran-xtable \
		R-cran-digest>0:${PORTSDIR}/security/R-cran-digest

USE_R_MOD=	yes
R_MOD_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
