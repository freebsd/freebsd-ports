PORTNAME=	knighttime
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Helpers for scheduling the dark-light cycle

USES=		cmake gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	config coreaddons dbusaddons holidays i18n \
		ecm:build
USE_QT=		base positioning
USE_XORG=	x11 xcb

.include <bsd.port.mk>
