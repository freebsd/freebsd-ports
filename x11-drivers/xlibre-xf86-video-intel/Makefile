PORTNAME=	xlibre-xf86-video-intel
PORTVERSION=	3.0.0.5
CATEGORIES=	x11-drivers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	XLibre legacy driver for Intel integrated graphics chipsets
WWW=		https://01.org/linuxgraphics/xf86-video-intel/

LICENSE=	MIT	# various
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	only Intel integrated GPUs on x86 are supported

LIB_DEPENDS=	libdrm_intel.so:graphics/libdrm \
		libxcb-util.so:x11/xcb-util libXvMC.so:x11/libXvMC

CONFLICTS_INSTALL=	xf86-video-intel

USES=		localbase xlibre xlibre-cat:driver,meson
USE_XORG=	pciaccess pixman x11 xcb xinerama xrandr xdamage xcursor xtst xfixes xrender xscrnsaver xext xv
CONFIGURE_ENV=	ac_cv_header_sys_sysinfo_h=no # XXX ports/242236
TEST_TARGET=	check

# XXX bug 214593: SNA crashes on pre-SandyBridge hardware
MESON_ARGS+=-Ddefault-accel=uxa -Dbacklight-helper=false

OPTIONS_DEFINE=	TOOLS UDEV UMS VALGRIND XVMC
OPTIONS_DEFAULT=UDEV XVMC UMS
OPTIONS_SUB=	yes

TOOLS_DESC=		Enables misc tools
TOOLS_MESON_TRUE=	tools

UDEV_DESC=		udev-based monitor hotplug detection
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd
UDEV_MESON_TRUE=	udev

XVMC_MESON_ENABLE=	xvmc

UMS_DESC=		Userspace Mode Setting for old chips.
UMS_LIB_DEPENDS=	libxcb-util.so:x11/xcb-util libXvMC.so:x11/libXvMC
UMS_MESON_TRUE=		ums

VALGRIND_DESC=		Enable valgrindified ioctls for debugging
VALGRIND_BUILD_DEPENDS=	valgrind:devel/valgrind
VALGRIND_MESON_TRUE=	valgrind

post-patch:
.if ${MESON_ARGS:M-Ddefault-accel=uxa}
	@${REINPLACE_CMD} '/^Default/s/SNA/UXA/' ${WRKSRC}/man/intel.man
.endif

.include <bsd.port.mk>
