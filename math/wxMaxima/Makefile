# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxMaxima
PORTVERSION=	16.04.1
PORTREVISION=	0
CATEGORIES=	math

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2

RUN_DEPENDS=	maxima:math/maxima

CONFIGURE_ARGS=	--program-prefix= --docdir=${DOCSDIR}

GH_TUPLE=	andrejv:${PORTNAME:tl}:Version-${DISTVERSION}
GNU_CONFIGURE=	yes

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

INFO=		wxmaxima

USE_GITHUB=	yes
USES=		autoreconf desktop-file-utils gettext makeinfo shared-mime-info
USE_WX=		3.0

WX_COMPS=	wx
WX_CONF_ARGS=	absolute

.include <bsd.port.mk>
