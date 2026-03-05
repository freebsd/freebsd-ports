PORTNAME=	systemsettings
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Control center to configure your Plasma Desktop

RUN_DEPENDS=	accountsservice>0:sysutils/accountsservice

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	activities auth colorscheme completion config configwidgets \
		coreaddons crash dbusaddons doctools guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kio kirigami2 \
		package plasma-workspace runner service solid \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative
USE_XORG=	x11

.include <bsd.port.mk>
