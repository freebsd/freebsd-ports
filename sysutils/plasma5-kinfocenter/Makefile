PORTNAME=	kinfocenter
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 utility providing system information
WWW=		https://www.kde.org/plasma-desktop

RUN_DEPENDS=	clinfo:devel/clinfo \
		dmidecode:sysutils/dmidecode  \
		glxinfo:graphics/mesa-demos \
		lscpu:sysutils/lscpu \
		vulkaninfo:graphics/vulkan-tools \
		wayland-info:graphics/wayland-utils \
		xdpyinfo:x11/xdpyinfo

USES=		cmake compiler:c++11-lib gettext kde:5 pkgconfig qt:5 tar:xz \
		xorg
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		init jobwidgets kcmutils kdeclarative kio package service \
		solid widgetsaddons windowsystem \
		doctools:build ecm:build \
		kirigami2:run systemsettings:run
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	ice sm x11 xext

# TODO	-- this should be handled correctly...
LDFLAGS+=-ldevinfo

# install freebsd-logo and distrorc
post-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}/images
	${INSTALL_DATA} ${FILESDIR}/freebsd_logo.svg   ${STAGEDIR}/${DATADIR}/images/
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/xdg
	${INSTALL_DATA} ${FILESDIR}/kcm-about-distrorc ${STAGEDIR}/${PREFIX}/etc/xdg/
	${REINPLACE_CMD} -i "" -e "s#%%DATADIR%%#${DATADIR}#"  ${STAGEDIR}/${PREFIX}/etc/xdg/kcm-about-distrorc

.include <bsd.port.mk>
