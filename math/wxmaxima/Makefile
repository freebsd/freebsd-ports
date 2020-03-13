# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxmaxima
PORTVERSION=	20.02.4
PORTREVISION=	1
DISTVERSIONPREFIX=	Version-
CATEGORIES=	math

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	maxima:math/maxima

USES=		cmake desktop-file-utils shared-mime-info
USE_WX=		3.0
USE_GITHUB=	yes
GH_ACCOUNT=	wxMaxima-Developers
GH_TAGNAME=	68fead0

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}
WX_COMPS=	wx
WX_CONF_ARGS=	absolute

PORTDATA=	COPYING README README.md

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt
NLS_USES=	gettext

.include <bsd.port.mk>
