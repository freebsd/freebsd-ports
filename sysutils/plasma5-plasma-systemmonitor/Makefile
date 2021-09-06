PORTNAME=	plasma-systemmonitor
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 system monitor

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 \
		localbase pathfix qt:5 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons dbusaddons \
		ecm globalaccel i18n itemmodels kdeclarative kio libksysguard \
		newstuff package service widgetsaddons windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
