PORTNAME=	kaccounts-providers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-providers

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libkaccounts.so:net-im/kaccounts-integration \
		libaccounts-qt5.so:net-im/libaccounts-qt@qt5 \
		libsignon-qt5.so:sysutils/signond@qt5

USES=		cmake compiler:c++11-lang gettext gnome kde:5 pkgconfig qt:5 \
		tar:xz
USE_GNOME=	intltool
USE_KDE=	config coreaddons i18n kdeclarative kio package service \
		ecm:build
USE_QT=		concurrent core dbus declarative gui location network \
		webchannel webengine xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=	DOCS

#install to ${LOCALBASE}:
pre-configure:
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' \
		${WRKSRC}/webkit-options/CMakeLists.txt

.include <bsd.port.mk>
