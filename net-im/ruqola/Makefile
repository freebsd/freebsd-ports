# $FreeBSD$

PORTNAME=	ruqola
DISTVERSION=	1.0.0-246
DISTVERSIONSUFFIX=	-g3b35804a
CATEGORIES=	net-im kde

MAINTAINER=	kde@FreeBSD
COMMENT=	Rocketchat client

LIB_DEPENDS=	libqt5keychain.so:security/qtkeychain \
		libsecret-1.so:security/libsecret

USES=		cmake gnome localbase:ldflags kde:5 qt:5
USE_GNOME=	glib20
USE_KDE=	ecm coreaddons crash i18n kirigami2 notifications syntaxhighlighting
USE_QT=		core dbus declarative declarative gui network networkauth \
		websockets widgets \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	3b35804a

.include <bsd.port.mk>
