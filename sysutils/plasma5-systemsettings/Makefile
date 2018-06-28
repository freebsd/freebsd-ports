# $FreeBSD$

PORTNAME=	systemsettings
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 system settings

USES=		cmake:outsource compiler:c++11-lib cpe gettext kde:5 qt:5 tar:xz
USE_KDE=	activities activities-stats auth codecs completion config \
		configwidgets coreaddons crash dbusaddons doctools ecm i18n \
		iconthemes itemviews jobwidgets js kcmutils kdeclarative khtml \
		kio kirigami2 package parts service sonnet textwidgets \
		widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus gui network qml quick widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>

