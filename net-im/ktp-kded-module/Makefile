PORTNAME=	ktp-kded-module
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net-im kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Module for integration of instant messaging into KDE Workspaces
WWW=		https://community.kde.org/KTp

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libtelepathy-qt5.so:net-im/telepathy-qt \
		libKTpCommonInternals.so:net-im/ktp-common-internals

USES=		compiler:c++11-lang cmake gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	activities auth codecs completion config configwidgets coreaddons \
		dbusaddons i18n idletime jobwidgets kcmutils kio notifications \
		service solid wallet widgetsaddons windowsystem
USE_QT=		concurrent core dbus gui network sql widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
