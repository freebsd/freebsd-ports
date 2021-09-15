PORTNAME=	ruqola
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	net-im kde

PATCH_SITES=	https://invent.kde.org/network/ruqola/-/commit/
PATCHFILES=	41dd72101605cf1b97a01ab9d3bfa675358066c2.diff:-p1 \
		fbb4979c96f4d5b7df8fbd59591fb6ec3d489e05.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocketchat client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret

USES=		cmake compiler:c++11-lang gnome kde:5 localbase:ldflags qt:5
USE_GNOME=	glib20
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons i18n iconthemes itemviews jobwidgets kio kirigami2 \
		notifications notifyconfig service solid sonnet syntaxhighlighting \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus declarative declarative gui multimedia \
		network networkauth speech xml websockets widgets \
		buildtools_build qmake_build testlib_build

KDE_INVENT=	8dd830a661f1b3e55b3e18f63594f72dcedd0596 network

PLIST_SUB=	SO_VER=${DISTVERSION}

.include <bsd.port.mk>
