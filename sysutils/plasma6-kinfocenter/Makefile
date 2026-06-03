PORTNAME=	kinfocenter
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	sysutils kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	View information about your computer's hardware

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
RUN_DEPENDS=	aha:textproc/aha \
		hwdata>0:misc/hwdata

USES=		cmake gettext gl kde:6 pkgconfig qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	auth colorscheme completion config configwidgets coreaddons \
		doctools i18n jobwidgets kcmutils kio package service solid \
		widgetsaddons \
		ecm:build \
		kirigami2:run systemsettings:run
USE_QT=		base declarative

OPTIONS_DEFINE=		AUX_UTILS
OPTIONS_DEFAULT=	AUX_UTILS

AUX_UTILS_DESC=		Install auxiliary packages
AUX_UTILS_RUN_DEPENDS=	clinfo:devel/clinfo \
			glxinfo:graphics/mesa-demos \
			lsblk:sysutils/lsblk \
			lscpu:sysutils/lscpu \
			pactl:audio/pulseaudio \
			sensors:sysutils/sensors \
			vulkaninfo:graphics/vulkan-tools \
			wayland-info:graphics/wayland-utils \
			xdpyinfo:x11/xdpyinfo \
			${${ARCH}_RUN_DEPENDS}

# Sync with sysutils/dmidecode
.for s in aarch64 amd64 armv6 armv7 i386 riscv64 riscv64sf
${s}_RUN_DEPENDS=	dmidecode:sysutils/dmidecode
.endfor

post-patch:
	 ${REINPLACE_CMD} '/usb.ids/s,/usr,${LOCALBASE},' ${WRKSRC}/kcms/usbview/usbdb.cpp

# install freebsd-logo and distrorc
post-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}/images
	${INSTALL_DATA} ${FILESDIR}/freebsd_logo.svg ${STAGEDIR}/${DATADIR}/images/
	${MKDIR} ${STAGEDIR}/${PREFIX}/etc/xdg
	${INSTALL_DATA} ${FILESDIR}/kcm-about-distrorc ${STAGEDIR}/${PREFIX}/etc/xdg/
	${REINPLACE_CMD} -i "" -e "s#%%DATADIR%%#${DATADIR}#" ${STAGEDIR}/${PREFIX}/etc/xdg/kcm-about-distrorc

.include <bsd.port.mk>
