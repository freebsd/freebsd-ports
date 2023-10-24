PORTNAME=	drkonqi
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 crash handler
WWW=		https://www.kde.org/plasma-desktop

LIB_DEPENDS=	libKUserFeedbackCore.so:deskutils/kuserfeedback

USES=		cmake compiler:c++11-lang kde:5 pkgconfig qt:5 tar:xz xorg
USE_KDE=	completion config coreaddons crash i18n idletime jobwidgets \
		kio notifications service syntaxhighlighting wallet \
		widgetsaddons windowsystem \
		ecm:build \
		itemmodels:run kdeclarative:run kirigami2:run
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build testlib:build
USE_XORG=	x11

.include <bsd.port.mk>
