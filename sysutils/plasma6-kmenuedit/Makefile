PORTNAME=	kmenuedit
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Menu Editor for Plasma Workspaces

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_XORG=	x11
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		dbusaddons doctools globalaccel i18n iconthemes itemviews \
		jobwidgets kio service solid sonnet widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_GL=		gl opengl
USE_QT=		base

.include <bsd.port.mk>
