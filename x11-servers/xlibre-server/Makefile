PORTNAME=	xlibre-server
PORTVERSION=	${XLIBRE_VER}
CATEGORIES=	x11-servers

MAINTAINER=	b-aazbsd@proton.me
COMMENT=	Xlibre X server
WWW=		https://github.com/X11Libre/xserver/

LICENSE=	MIT

CONFLICTS=	xorg-server

USES+=		xlibre-cat:server

OPTIONS_SUB=	YES
OPTIONS_DEFINE=	UDEV SUID NVIDIA_ABI INPUTTEST SEATD
OPTIONS_DEFAULT=UDEV SUID INPUTTEST SEATD

UDEV_DESC=		Enable udev. (For libinput & autoconfiguration/hotplug)
UDEV_MESON_TRUE=	udev udev_kms
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd

SUID_DESC=		Enable the setuid binary. (For starting X as a normal user)
SUID_MESON_TRUE=	suid_wrapper

OPTIONS_DEFAULT_amd64=	NVIDIA_ABI
OPTIONS_DEFAULT_i386=	NVIDIA_ABI

NVIDIA_ABI_DESC=	Rebuild XLibre drivers if switched! Fixes for NVIDIA drivers.
NVIDIA_ABI_MESON_TRUE=	legacy_nvidia_padding legacy_nvidia_340x

INPUTTEST_DESC=		Build inputtest driver. (For testing and automation)
INPUTTEST_MESON_TRUE=	xf86-input-inputtest

SEATD_DESC=		Build with seatd support. (For running X unprivileged)
SEATD_MESON_TRUE=	seatd_libseat
SEATD_LIB_DEPENDS=	libseat.so:sysutils/seatd

LIB_DEPENDS+=	libxcvt.so:x11/libxcvt \
		libdrm.so:graphics/libdrm \
		libepoll-shim.so:devel/libepoll-shim \
		libepoxy.so:graphics/libepoxy

MESON_ARGS+=	-Dlog_dir=/var/log \
		-Ddrm=true

PLIST_SUB+=	FONTPATHD="${FONTPATHD:S,^${PREFIX}/,,}"

USE_XORG+=	pciaccess

USE_GL+=	gbm

.include "../xlibre-server/Makefile.common"

OLDMODULEDIR=	/lib/xorg/modules
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	@${MKDIR} ${STAGEDIR}${PREFIX}${OLDMODULEDIR}/extensions
	@${MKDIR} ${STAGEDIR}${PREFIX}${OLDMODULEDIR}/drivers
	@${MKDIR} ${STAGEDIR}${PREFIX}${OLDMODULEDIR}/input
	@${MKDIR} ${STAGEDIR}${FONTPATHD}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
	@${INSTALL_DATA} ${FILESDIR}/20-evdev-kbd.conf \
		${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
.include <bsd.port.post.mk>
