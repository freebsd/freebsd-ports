PORTNAME=	kaccounts-providers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-providers

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libkaccounts6.so:net-im/kaccounts-integration \
		libaccounts-qt6.so:net-im/libaccounts-qt \
		libsignon-qt6.so:sysutils/signond

USES=		cmake compiler:c++11-lang gettext gnome kde:6 pkgconfig qt:6 \
		tar:xz
USE_GNOME=	intltool
USE_KDE=	config coreaddons i18n kdeclarative kio package service \
		ecm:build
USE_QT=		base declarative webchannel

OPTIONS_DEFINE=		DOCS WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE
OPTIONS_SUB=		yes

WEBENGINE_DESC=		Nextcloud account plugin (requires QtWebEngine)
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineQuick

#install to ${LOCALBASE}:
pre-configure:
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' \
		${WRKSRC}/webkit-options/CMakeLists.txt

.include <bsd.port.mk>
