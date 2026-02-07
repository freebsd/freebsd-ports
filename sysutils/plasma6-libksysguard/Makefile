PORTNAME=	libksysguard
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to retrieve information on the current status of computer hardware

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	auth colorscheme completion config configwidgets coreaddons \
		globalaccel i18n iconthemes jobwidgets kio newstuff package \
		service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		5compat base declarative positioning webchannel webengine
USE_XORG=	x11

.include <bsd.port.mk>
