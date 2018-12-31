# $FreeBSD$

PORTNAME=	plasma-browser-integration
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	www kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 components to integrate browsers into the desktop

USES=		compiler:c++11-lang cmake kde:5 qt:5 tar:xz
USE_KDE=	activities config coreaddons i18n kio notifications package \
		plasma-framework runner service windowsystem
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
