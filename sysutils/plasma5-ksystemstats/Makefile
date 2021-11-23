PORTNAME=	ksystemstats
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

PATCH_SITES=	https://invent.kde.org/plasma/ksystemstats/-/commit/
PATCHFILES=	15a03830f7d77e63c98c018f466796099aa482c5.diff:-p1 \
		cfcb1ed7962290c868a2027151273947da3aa1d8.diff:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to report system activity

LIB_DEPENDS+=	libudev.so:devel/libudev-devd

USES=		cmake compiler:c++17-lang kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons dbusaddons i18n kio libksysguard service \
		solid
USE_QT=		concurrent core dbus gui network \
		buildtools_build qmake_build testlib_build

.include <bsd.port.mk>
