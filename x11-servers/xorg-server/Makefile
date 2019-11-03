# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	xorg-server
PORTVERSION?=	1.18.4
PORTREVISION?=	12
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
OPTIONS_RADIO_CONF=	DEVD HAL
DEVD_DESC=	Use devd for autoconfiguration of input devices
HAL_DESC=	Use hald for autoconfiguration of input devices
SUID_DESC=	Install the Xorg server with setuid bit set
OPTIONS_DEFAULT=DEVD SUID

OPTIONS_EXCLUDE_sparc64=	HAL

.include <bsd.port.options.mk>

USES=		gmake gl libtool perl5 ssl tar:bzip2 xorg xorg-cat:xserver
USE_PERL5=	build
USE_GL+=	gl
USE_XORG+=	pixman xau xdmcp xfont xkbfile xorgproto xshmfence xtrans
CONFIGURE_ARGS+=--without-doxygen --without-xmlto --without-fop \
		--localstatedir=/var --with-shared-memory-dir=/tmp \
		--disable-config-udev --disable-config-udev-kms \
		--without-dtrace --enable-glamor
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
CONFIGURE_ARGS+=--disable-xorg
# for slave ports we need to overwrite PLIST, so it doesn't overwrite
# PLIST_FILES, with the masterport plist.
PLIST=		${.CURDIR}/pkg-plist
.endif

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	libhal.so:sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal
.else
CONFIGURE_ARGS+=	--disable-config-hal
.endif

# We handle Xorg setuid in the plist. This allows to build xorg-server as a user.
CONFIGURE_ARGS+=--disable-install-setuid

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

.if ${ARCH} == "sparc64"
PLIST_SUB+=	SPARC64=""
.else
PLIST_SUB+=	SPARC64="@comment "
.endif

.if ${PORT_OPTIONS:MSUID}
pre-everything::
	@${ECHO_MSG} "By default, the X Server installs as a set-user-id root binary. When run by"
	@${ECHO_MSG} "a normal user, it checks arguments and environment as done in the x11/wrapper"
	@${ECHO_MSG} "port before handling them normally.  If you are concerned about the security"
	@${ECHO_MSG} "of this, but still want to run an X Server (for example using xdm/kdm/gdm,"
	@${ECHO_MSG} "which will still run the server as root), you can cancel the build and set"
	@${ECHO_MSG} "xorg-server_UNSET=SUID in /etc/make.conf."
.endif

post-patch:
	@${REINPLACE_CMD} 's/test.*-traditional.*;/true;/' \
		${WRKSRC}/configure
# build libglx.so but don't install it yet. which is done in pre-install.
	@${REINPLACE_CMD} -e 's|@GLX_TRUE@GLXMODS =|@GLX_BOGUS@GLXMODS =|g' \
		-e 's|^LTLIBRARIES = |LTLIBRARIES = libglx.la |g' \
		${WRKSRC}/hw/xfree86/dixmods/Makefile.in

post-configure:
.if ${PORT_OPTIONS:MDEVD}
	@${REINPLACE_CMD} -e 's|config\.c|config.c devd.c|g' \
		-e 's|config\.lo|config.lo devd.lo|g' \
		${WRKSRC}/config/Makefile
	@${REINPLACE_CMD} -e 's|^/\* #undef CONFIG_UDEV \*/|#define CONFIG_DEVD 1|' \
		${WRKSRC}/include/dix-config.h
.endif

.if ${SLAVE_PORT} == "no"
post-install:
# The .xorg dir because else the xorg-server might not load the correct
# libglx module.
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg
	${INSTALL_LIB} ${WRKSRC}/hw/xfree86/dixmods/.libs/libglx.so \
		${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/.xorg/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/X11/xorg.conf.d
.endif # ! SLAVE_PORT

.include <bsd.port.post.mk>
