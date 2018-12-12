# $FreeBSD$

PORTNAME=	plasma-browser-integration
DISTVERSION=	5.10.95.20181011
PORTREVISION=	1
CATEGORIES=	www kde
PKGNAMEPREFIX=	plasma5- # this port is not yet using CATEGORIES=kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 components to integrate browsers into the desktop

USES=		compiler:c++11-lang cmake:outsource kde:5 qt:5
USE_KDE=	activities config coreaddons i18n kio notifications package \
		plasma-framework runner service windowsystem
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	KDE
GH_TAGNAME=	c593654

.include <bsd.port.mk>
