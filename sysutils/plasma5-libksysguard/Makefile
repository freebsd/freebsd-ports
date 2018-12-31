# $FreeBSD$

PORTNAME=	libksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 library to track and control running processes

USES=		cmake compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		iconthemes package plasma-framework service widgetsaddons \
		windowsystem
USE_QT=		core dbus gui network script webkit widgets x11extras xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
