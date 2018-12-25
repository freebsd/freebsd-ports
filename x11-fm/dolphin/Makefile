# $FreeBSD$

PORTNAME=	dolphin
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-fm kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE filemanager dolphin

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${QT_PLUGINDIR}/ffmpegthumbs.so:multimedia/kdemultimedia-ffmpegthumbs \
		${QT_PLUGINDIR}/gsthumbnail.so:graphics/kdegraphics-thumbnailers \
		${QT_PLUGINDIR}/audiothumbnail.so:devel/kio-extras

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	activities attica auth baloo baloo-widgets bookmarks codecs \
		completion config configwidgets coreaddons crash dbusaddons \
		doctools ecm emoticons filemetadata i18n iconthemes init \
		itemmodels itemviews jobwidgets kcmutils kde-cli-tools \
		kdelibs4support kio newstuff notifications parts service \
		solid sonnet texteditor textwidgets widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus gui network phonon4 widgets xml \
		buildtools_build qmake_build

SHLIB_VER=	5.0.0
PLIST_SUB+=	SHLIB_VER="${SHLIB_VER}" \
		SHLIB_SHVER="${SHLIB_VER:R:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
