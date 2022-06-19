PORTNAME=	ruqola
MASTER_SITES=	KDE/stable/${PORTNAME}/
DISTVERSION=	1.7.2
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocketchat client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret

USES=		cmake compiler:c++11-lang gnome kde:5 localbase:ldflags qt:5 tar:xz
USE_GNOME=	glib20
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons i18n iconthemes idletime itemviews jobwidgets kio kirigami2 \
		notifications notifyconfig prison service solid sonnet syntaxhighlighting \
		textwidgets widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		concurrent core dbus declarative declarative gui multimedia \
		network networkauth speech xml websockets widgets \
		buildtools_build qmake_build testlib_build

PLIST_SUB=	SO_VER=${DISTVERSION}

.include <bsd.port.mk>
