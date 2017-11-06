# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxMaxima
PORTVERSION=	17.05.1
DISTVERSIONPREFIX=	Version-
PORTREVISION=	0
CATEGORIES=	math

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2

RUN_DEPENDS=	maxima:math/maxima

GH_ACCOUNT=	andrejv
GH_PROJECT=	${PORTNAME:tl}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

USE_GITHUB=	yes
USES=		cmake desktop-file-utils gettext shared-mime-info
USE_WX=		3.0

WX_COMPS=	wx
WX_CONF_ARGS=	absolute

.include <bsd.port.mk>
