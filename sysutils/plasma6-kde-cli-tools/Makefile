PORTNAME=	kde-cli-tools
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tools based on KDE Frameworks to better interact with the system

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake desktop-file-utils gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_XORG=	x11
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		doctools i18n iconthemes jobwidgets kcmutils kdesu kio parts \
		pty service solid widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
