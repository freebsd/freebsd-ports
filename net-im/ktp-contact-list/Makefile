PORTNAME=	ktp-contact-list
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE instant messaging contact list application
WWW=		https://community.kde.org/KTp

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt \
		libtelepathy-logger-qt.so:net-im/telepathy-logger-qt5 \
		libKTpCommonInternals.so:net-im/ktp-common-internals

LICENSE=	LGPL21+

USES=		compiler:c++11-lang cmake gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n iconthemes jobwidgets kcmutils kio \
		notifications notifyconfig people service solid wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
