PORTNAME=	keysmith
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Application to generate two-factor authentication tokens
WWW=		https://invent.kde.org/utilities/keysmith

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake desktop-file-utils gettext kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	dbusaddons ecm i18n kirigami2 windowsystem
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 svg widgets \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
