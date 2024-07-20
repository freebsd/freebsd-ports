PORTNAME=	crow-translate
PORTVERSION=	2.11.1
CATEGORIES=	textproc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Translator using Google, Yandex Bing, LibreTranslate and Lingva
WWW=		https://crow-translate.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/ECM/cmake/ECMConfig.cmake:devel/kf6-extra-cmake-modules
LIB_DEPENDS=	libleptonica.so:graphics/leptonica \
		libtesseract.so:graphics/tesseract

USES=		cmake desktop-file-utils gstreamer kde:5 qt:5 xorg
USE_GITHUB=	yes
GH_TUPLE=	HatScripts:circle-flags:1c186db:circleflags/data/icons/third-party/circle-flags \
		vinceliuice:Fluent-icon-theme:2a80a5d:fluenticontheme/data/icons/third-party/fluent-icon-theme \
		crow-translate:QGitTag:3763898:qgittag/src/qgittag \
		crow-translate:QOnlineTranslator:148de2b:qonlinetranslator/src/qonlinetranslator \
		Skycoder42:QHotkey:eb7ddab:qhotkey/src/third-party/qhotkey \
		crow-translate:QTaskbarControl:d1b07c0:qtaskbarcontrol/src/third-party/qtaskbarcontrol \
		itay-grudev:SingleApplication:aede311:singleapplication/src/third-party/singleapplication
USE_KDE=	wayland
USE_QT=		concurrent core dbus gui multimedia network svg widgets \
		x11extras buildtools:build linguisttools:build qmake:build
USE_XORG=	ice sm x11 xcb xext

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/src/settings/autostartmanager/unixautostartmanager.cpp

.include <bsd.port.mk>
