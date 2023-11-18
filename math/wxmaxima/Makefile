PORTNAME=	wxmaxima
PORTVERSION=	23.11.0
DISTVERSIONPREFIX=	Version-
CATEGORIES=	math

MAINTAINER=	salvadore@FreeBSD.org
COMMENT=	WxWidgets GUI for the computer algebra system maxima
WWW=		https://wxmaxima-developers.github.io/wxmaxima/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	maxima:math/maxima

USES=		cmake compiler:c++14-lang desktop-file-utils shared-mime-info
USE_GITHUB=	yes
GH_ACCOUNT=	wxMaxima-Developers

USE_WX=		3.0
WX_COMPS=	wx
WX_CONF_ARGS=	absolute

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-CMakeLists.txt

.include <bsd.port.mk>
