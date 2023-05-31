PORTNAME=	plasma-systemmonitor
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 system monitor
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib desktop-file-utils gettext kde:5 \
		localbase pathfix qt:5 tar:xz xorg
USE_KDE=	attica auth codecs config configwidgets coreaddons dbusaddons \
		ecm globalaccel i18n itemmodels kdeclarative kio ksystemstats \
		libksysguard newstuff package service widgetsaddons \
		windowsystem xmlgui
USE_QT=		concurrent core dbus declarative gui network quickcontrols2 \
		widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
