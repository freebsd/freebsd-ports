PORTNAME=	dolphin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-fm kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE filemanager dolphin
WWW=		https://userbase.kde.org/Dolphin

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	activities attica auth bookmarks codecs \
		completion config configwidgets coreaddons crash dbusaddons \
		emoticons filemetadata i18n iconthemes init \
		itemmodels itemviews jobwidgets kcmutils kde-cli-tools \
		kio newstuff notifications parts service \
		solid sonnet texteditor textwidgets widgetsaddons \
		windowsystem xmlgui ecm:build
USE_QT=		concurrent core dbus gui network phonon4 widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

SHLIB_VER=	5.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS
OPTIONS_EXCLUDE_purecap=	DOCS

.include <bsd.port.pre.mk>

.if !${ABI:Mpurecap}
RUN_DEPENDS=	${QT_PLUGINDIR}/kf5/kio/thumbnail.so:devel/kio-extras \
		${QT_PLUGINDIR}/gsthumbnail.so:graphics/kdegraphics-thumbnailers \
		${QT_PLUGINDIR}/ffmpegthumbs.so:multimedia/kdemultimedia-ffmpegthumbs
USES+=		desktop-file-utils
USE_KDE+=	baloo baloo-widgets
.endif

.include <bsd.port.post.mk>
