# $FreeBSD$

PORTNAME=	zeroconf-ioslave
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Network monitor for DNS-SD services (Zeroconf)

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons dnssd i18n kio service
USE_QT=		core dbus network \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
