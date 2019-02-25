# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxmaxima
PORTVERSION=	19.02.0
PORTREVISION=	1
DISTVERSIONPREFIX=	Version-
CATEGORIES=	math

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2

RUN_DEPENDS=	maxima:math/maxima

USES=		cmake desktop-file-utils gettext shared-mime-info
USE_WX=		3.0
USE_GITHUB=	yes
GH_ACCOUNT=	wxMaxima-Developers

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}
WX_COMPS=	wx
WX_CONF_ARGS=	absolute

.include <bsd.port.mk>
