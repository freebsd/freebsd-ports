# $FreeBSD$

PORTNAME=	ruqola
DISTVERSION=	1.0.0-246
DISTVERSIONSUFFIX=	-g3b35804a
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Rocketchat client

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret

USES=		cmake compiler:c++11-lang gnome kde:5 localbase:ldflags qt:5
USE_GNOME=	glib20
USE_KDE=	ecm coreaddons crash i18n kirigami2 notifications syntaxhighlighting
USE_QT=		core dbus declarative declarative gui network networkauth \
		websockets widgets \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	3b35804a

.include <bsd.port.mk>
