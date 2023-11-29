PORTNAME=	kde-cli-tools
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools based on KDE Frameworks to better interact with the system

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons doctools i18n iconthemes kcmutils kdesu kio \
		parts service windowsystem \
		ecm:build
USE_QT=		base svg

.include <bsd.port.mk>
