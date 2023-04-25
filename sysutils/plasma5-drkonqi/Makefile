PORTNAME=	drkonqi
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 crash handler
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libKUserFeedbackCore.so:deskutils/kuserfeedback

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		i18n idletime jobwidgets kdeclarative kio notifications \
		service syntaxhighlighting wallet widgetsaddons windowsystem \
		xmlrpcclient \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets x11extras \
		xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
