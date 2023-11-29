PORTNAME=	plasma-systemmonitor
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Interface for monitoring system sensors, process information and other system resources

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config dbusaddons globalaccel i18n itemmodels kio \
		kirigami-addons libksysguard newstuff package service \
		windowsystem \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
