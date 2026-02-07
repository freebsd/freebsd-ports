PORTNAME=	kaccounts-providers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	System to administer web accounts for the KDE desktop
WWW=		https://projects.kde.org/projects/kdereview/kaccounts-providers

LIB_DEPENDS=	libaccounts-glib.so:net-im/libaccounts-glib \
		libkaccounts6.so:net-im/kaccounts-integration \
		libaccounts-qt6.so:net-im/libaccounts-qt@qt6 \
		libsignon-qt6.so:sysutils/signond@qt6

USES=		cmake compiler:c++11-lang gettext gnome kde:6 pkgconfig qt:6 \
		tar:xz
USE_GNOME=	intltool
USE_KDE=	config coreaddons i18n kdeclarative kio package service \
		ecm:build
USE_QT=		base declarative webchannel webengine

OPTIONS_DEFINE=	DOCS

#install to ${LOCALBASE}:
pre-configure:
	${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,' \
		${WRKSRC}/webkit-options/CMakeLists.txt

.include <bsd.port.mk>
