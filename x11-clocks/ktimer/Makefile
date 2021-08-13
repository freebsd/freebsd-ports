PORTNAME=	ktimer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-clocks kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Countdown launcher for KDE

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools i18n iconthemes jobwidgets kio \
		notifications service solid widgetsaddons windowsystem xmlgui \
		ecm_build
USE_QT=		concurrent core dbus gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
