# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	wxmaxima
PORTVERSION=	20.04.0
DISTVERSIONPREFIX=	Version-
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	maxima:math/maxima

USES=		cmake compiler:c++11-lang desktop-file-utils shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	wxMaxima-Developers

USE_WX=		3.0
WX_COMPS=	wx
WX_CONF_ARGS=	absolute

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}
PORTDATA=	COPYING README README.md

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

.include <bsd.port.mk>
