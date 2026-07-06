PORTNAME=	keysmith
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Application to generate two-factor authentication tokens
WWW=		https://invent.kde.org/utilities/keysmith

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsodium.so:security/libsodium

USES=		cmake desktop-file-utils gettext kde:6 pkgconfig qt:6 tar:xz \
		xorg
USE_KDE=	config coreaddons dbusaddons i18n kirigami-addons \
		kirigami2 prison qqc2-desktop-style windowsystem \
		ecm:build
USE_QT=		base declarative svg
USE_XORG=	x11

.include <bsd.port.mk>
