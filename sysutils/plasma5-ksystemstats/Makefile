PORTNAME=	ksystemstats
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to report system activity

LIB_DEPENDS+=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kio libksysguard service \
		solid
USE_QT=		concurrent core dbus gui network \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
