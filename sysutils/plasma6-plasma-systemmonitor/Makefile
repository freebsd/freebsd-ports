PORTNAME=	plasma-systemmonitor
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Interface for monitoring system sensors, process information and other system resources

USES=		cmake gettext gl kde:6 python:run qt:6 shebangfix tar:xz xorg
USE_KDE=	attica config coreaddons dbusaddons globalaccel i18n \
		itemmodels kio kirigami-addons libksysguard newstuff package \
		service windowsystem \
		ecm:build \
		ksystemstats:run
USE_QT=		base declarative
USE_XORG=	x11
USE_GL=		gl opengl

SHEBANG_FILES=	kconf_update/plasma-systemmonitor-replace-vmpss.py

.include <bsd.port.mk>
