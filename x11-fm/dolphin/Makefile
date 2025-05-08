PORTNAME=	dolphin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-fm kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE filemanager dolphin
WWW=		https://userbase.kde.org/Dolphin

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpackagekitqt6.so:ports-mgmt/packagekit-qt
RUN_DEPENDS=	${QT_PLUGINDIR}/kf6/thumbcreator/ffmpegthumbs.so:multimedia/kdemultimedia-ffmpegthumbs \
		${QT_PLUGINDIR}/kf6/thumbcreator/gsthumbnail.so:graphics/kdegraphics-thumbnailers \
		${QT_PLUGINDIR}/kf6/kio/thumbnail.so:devel/kio-extras

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:6 qt:6 \
		tar:xz xorg
USE_KDE=	activities attica auth baloo baloo-widgets bookmarks codecs \
		completion config configwidgets coreaddons crash dbusaddons \
		itemmodels itemviews jobwidgets kcmutils kde-cli-tools kio \
		newstuff notifications parts phonon service solid sonnet \
		texteditor textwidgets userfeedback widgetsaddons windowsystem \
		xmlgui \
		doctools:build ecm:build
USE_QT=		base imageformats:run
USE_XORG=	x11

SHLIB_VER=	6.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
