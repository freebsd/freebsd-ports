# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	xorg-server
PORTVERSION?=	1.20.8
PORTEPOCH?=	1
CATEGORIES=	x11-servers
MASTER_SITES=	XORG/individual/xserver
DISTNAME=	xorg-server-${PORTVERSION}

MAINTAINER=	x11@FreeBSD.org
COMMENT?=	X.Org X server and related programs

LICENSE=	MIT

RUN_DEPENDS+=	xkeyboard-config>=2.5:x11/xkeyboard-config \
		xkbcomp:x11/xkbcomp

SLAVE_PORT?=	no

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	SUID
OPTIONS_RADIO=	CONF
OPTIONS_RADIO_CONF=	DEVD UDEV
OPTIONS_DEFAULT=	SUID
OPTIONS_DEFAULT_FreeBSD_11=	DEVD
OPTIONS_DEFAULT_FreeBSD_12=	UDEV
OPTIONS_DEFAULT_FreeBSD_13=	UDEV
OPTIONS_DEFAULT+=	${OPTIONS_DEFAULT_${OPSYS}_${OSREL:R}}

SUID_DESC=	Install setuid wrapper to allow startx as non-root
CONF_DESC=	Backend to use for input device configuration
DEVD_DESC=	Use devd for autoconfiguration of input devices
UDEV_DESC=	Use udev via libudev-devd for autoconfiguration of input devices

DEVD_CONFIGURE_ENABLE=	config-devd
SUID_CONFIGURE_ENABLE=	suid-wrapper
SUID_CONFIGURE_ON=	--libexecdir=${PREFIX}/bin	# set SUID_WRAPPER_DIR
UDEV_CONFIGURE_ENABLE=	config-udev
UDEV_CONFIGURE_ON=	--disable-config-udev-kms
UDEV_LIB_DEPENDS=	libudev.so:devel/libudev-devd

.include <bsd.port.options.mk>

FONTPATH_ROOT?=	${LOCALBASE}/share/fonts
FONTPATHD?=	${PREFIX}/etc/X11/fontpath.d
DEFAULT_FONTPATH_LIST= \
	${FONTPATH_ROOT}/misc/	\
	${FONTPATH_ROOT}/TTF/ \
	${FONTPATH_ROOT}/OTF/ \
	${FONTPATH_ROOT}/Type1/ \
	${FONTPATH_ROOT}/100dpi/ \
	${FONTPATH_ROOT}/75dpi/ \
	catalogue:${FONTPATHD}
DEFAULT_FONTPATH_CMD=${ECHO_CMD} ${DEFAULT_FONTPATH_LIST} | ${TR} ' ' ,
PLIST_SUB+=	FONTPATHD="${FONTPATHD:S,^${PREFIX}/,,}"

USES=		compiler:c11 gl gmake perl5 ssl xorg xorg-cat:xserver
USE_PERL5=	build
USE_GL+=	gl
USE_XORG+=	pixman xau xdmcp xfont2 xkbfile xorgproto xshmfence xtrans
CONFIGURE_ARGS+=--without-doxygen --without-xmlto --without-fop \
		--with-default-font-path="$$(${DEFAULT_FONTPATH_CMD})" \
		--without-dtrace --with-shared-memory-dir=/tmp \
		--disable-install-setuid --disable-unit-tests
INSTALL_TARGET=	install-strip

.if ${SLAVE_PORT} == "no" || ${PORTNAME} == "xephyr" || ${PORTNAME} == "xwayland"
LIB_DEPENDS+=	libdrm.so:graphics/libdrm \
		libepoxy.so:graphics/libepoxy
.else
BUILD_DEPENDS+=	libepoxy>0:graphics/libepoxy	# only for configure
.endif

.if ${SLAVE_PORT} == "no"
USE_GL+=	gbm
USE_XORG+=	pciaccess
CONFIGURE_ARGS+=--disable-dmx --disable-xephyr --disable-xnest --disable-xvfb \
		--disable-xwayland --enable-xcsecurity
SUB_FILES=	pkg-install pkg-deinstall
.else
CONFIGURE_ARGS+=	--disable-xorg
OPTIONS_EXCLUDE=	DEVD UDEV SUID
# Set PLIST for slave ports so they only need to set PLIST_FILES
PLIST=		${.CURDIR}/pkg-plist
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure

.if ${SLAVE_PORT} == "no"
post-install:
# Avoid conflict with nvidia-driver, move libglx.so into .xorg directory
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg
	${MV} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/libglx.so \
		${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
	@${MKDIR} ${STAGEDIR}${FONTPATHD}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
	@${INSTALL_DATA} ${FILESDIR}/20-evdev-kbd.conf \
		${STAGEDIR}${PREFIX}/share/X11/xorg.conf.d
.endif # ! SLAVE_PORT

.include <bsd.port.post.mk>
