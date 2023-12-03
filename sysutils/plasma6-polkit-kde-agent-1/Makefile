PORTNAME=	polkit-kde-agent-1
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Manages the power consumption settings of a Plasma shell

LIB_DEPENDS=	libpolkit-qt6-agent-1.so:sysutils/polkit-qt-1-devel@qt6

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	coreaddons crash dbusaddons i18n iconthemes widgetsaddons \
		windowsystem \
		ecm:build
USE_QT=		base declarative tools
USE_XORG=	x11

.include <bsd.port.mk>
