PORTNAME=	plasma-disks
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Monitors S.M.A.R.T. capable devices for imminent failure

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_KDE=	auth config coreaddons dbusaddons i18n kcmutils kio \
		notifications package service solid \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base declarative

.include <bsd.port.mk>
