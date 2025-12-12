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
OPTIONS_DEFINE=	UDEV SUID
OPTIONS_DEFAULT=UDEV SUID

UDEV_DESC= Enable udev (For libinput & autoconfiguration/hotplug).
UDEV_MESON_ON=	-Dudev=true -Dudev_kms=true
UDEV_MESON_OFF=	-Dudev=false -Dudev_kms=false
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd

SUID_DESC= Enable the setuid binary (For starting X as a normal user).
SUID_MESON_ON=		-Dsuid_wrapper=true
SUID_MESON_OFF=		-Dsuid_wrapper=false

LIB_DEPENDS+=	libxcvt.so:x11/libxcvt \
		libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy \
		libepoll-shim.so:devel/libepoll-shim

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
