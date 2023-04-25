PORTNAME=	ruqola
MASTER_SITES=	KDE/stable/${PORTNAME}/
DISTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocket.Chat client
WWW=		https://apps.kde.org/ruqola/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain@qt5 \
		libsecret-1.so:security/libsecret

USES=		cmake compiler:c++11-lang gnome kde:5 localbase:ldflags qt:5 tar:xz xorg
USE_GNOME=	glib20
USE_KDE=	archive auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons i18n iconthemes idletime itemviews \
		jobwidgets kio kirigami2 notifications notifyconfig prison \
		purpose service solid sonnet syntaxhighlighting textwidgets \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus declarative declarative gui multimedia \
		network networkauth speech sql xml websockets widgets \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

PLIST_SUB=	SO_VER=${DISTVERSION}

.include <bsd.port.mk>
