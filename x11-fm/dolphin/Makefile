PORTNAME=	dolphin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-fm kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE filemanager dolphin
WWW=		https://userbase.kde.org/Dolphin

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${QT_PLUGINDIR}/kf5/thumbcreator/ffmpegthumbs.so:multimedia/kdemultimedia-ffmpegthumbs \
		${QT_PLUGINDIR}/kf5/thumbcreator/gsthumbnail.so:graphics/kdegraphics-thumbnailers \
		${QT_PLUGINDIR}/kf5/kio/thumbnail.so:devel/kio-extras

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 qt:5 \
		tar:xz xorg
USE_KDE=	activities attica auth baloo baloo-widgets bookmarks codecs \
		completion config configwidgets coreaddons crash dbusaddons \
		emoticons filemetadata i18n iconthemes init \
		itemmodels itemviews jobwidgets kcmutils kde-cli-tools \
		kio newstuff notifications parts phonon service \
		solid sonnet texteditor textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

SHLIB_VER=	5.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
