PORTNAME=	ruqola
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocketchat client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret

USES=		cmake compiler:c++11-lang gnome kde:5 localbase:ldflags qt:5
USE_GNOME=	glib20
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons ecm i18n iconthemes itemviews jobwidgets kio kirigami2 \
		notifications notifyconfig service sonnet syntaxhighlighting \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools_build
USE_QT=		concurrent core dbus declarative declarative gui multimedia \
		network networkauth speech xml 	websockets widgets \
		buildtools_build qmake_build

KDE_INVENT=	9a770478085e737b291db2b50fe76a9b7704cd7d network

PLIST_SUB=	SO_VER=${DISTVERSION} 

.include <bsd.port.mk>
