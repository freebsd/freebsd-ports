PORTNAME=	kio-zeroconf
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network monitor for DNS-SD services (Zeroconf)

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz xorg
USE_KDE=	config coreaddons dbusaddons dnssd i18n kio service
USE_QT=		concurrent core dbus network \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
