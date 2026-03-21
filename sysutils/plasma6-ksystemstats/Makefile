PORTNAME=	ksystemstats
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin based system monitoring daemon

LIB_DEPENDS=	libudev.so:devel/libudev-devd

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	coreaddons dbusaddons i18n kio libksysguard solid \
		ecm:build
USE_QT=		base

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_KF6NetworkManagerQt

.include <bsd.port.mk>
