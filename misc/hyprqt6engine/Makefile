PORTNAME=	hyprqt6engine
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	misc

PATCH_SITES=	https://github.com/hyprwm/hyprqt6engine/commit/
PATCHFILES+=	9063e6837b4e282a73b052a0c0371916daccf50a.patch:-p1 # Fix configure with Qt 6.10

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Qt6 theme provider for Hyprland
WWW=		https://github.com/hyprwm/hyprqt6engine

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake gl kde:6 localbase:ldflags pkgconfig qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_LDCONFIG=	yes

USE_GL=		gl opengl
USE_QT=		base
USE_KDE=	colorscheme config iconthemes

PLIST_FILES=	lib/libhyprqt6engine-common.so \
		${QT_PLUGINDIR}/platformthemes/libhyprqt6engine.so \
		${QT_PLUGINDIR}/styles/libhypr-style.so

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${LOCALBASE}&|' \
		${WRKSRC}/common/config/ConfigManager.cpp
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/common/common.cpp

.include <bsd.port.mk>
