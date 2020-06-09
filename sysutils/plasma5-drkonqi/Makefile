# $FreeBSD$

PORTNAME=	drkonqi
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 crash handler

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		 crash i18n idletime jobwidgets kio notifications \
		service syntaxhighlighting wallet widgetsaddons \
		windowsystem xmlrpcclient
USE_QT=		concurrent core dbus gui network widgets x11extras xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
