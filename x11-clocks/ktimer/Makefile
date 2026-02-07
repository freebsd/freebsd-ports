PORTNAME=	ktimer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11-clocks kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Countdown launcher for KDE
WWW=		https://utils.kde.org/projects/ktimer/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		dbusaddons doctools i18n iconthemes jobwidgets kio \
		notifications service solid statusnotifieritem widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
