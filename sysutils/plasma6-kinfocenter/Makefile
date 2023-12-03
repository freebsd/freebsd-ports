PORTNAME=	kinfocenter
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	View information about your computer's hardware

RUN_DEPENDS=	clinfo:devel/clinfo \
		glxinfo:graphics/mesa-demos \
		lscpu:sysutils/lscpu \
		vulkaninfo:graphics/vulkan-tools \
		xdpyinfo:x11/xdpyinfo

USES=		cmake gettext gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	auth colorscheme completion config configwidgets coreaddons \
		doctools i18n jobwidgets kcmutils kio package service solid \
		widgetsaddons \
		ecm:build \
		kirigami2:run systemsettings:run
USE_QT=		base declarative

.include <bsd.port.mk>
