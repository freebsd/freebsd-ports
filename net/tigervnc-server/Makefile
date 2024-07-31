PKGNAMESUFFIX=	-server

COMMENT=	TigerVNC Server
WWW=		https://tigervnc.org/

PATCH_DEPENDS+=	${NONEXISTENT}:x11-servers/xorg-server:patch
BUILD_DEPENDS+=	${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri \
		${LOCALBASE}/libdata/pkgconfig/fontutil.pc:x11-fonts/font-util \
		${LOCALBASE}/include/libxcvt/libxcvt.h:x11/libxcvt \
		bash:shells/bash
LIB_DEPENDS=	libxshmfence.so:x11/libxshmfence \
		libnettle.so:security/nettle \
		libgmp.so:math/gmp \
		libavcodec.so:multimedia/ffmpeg
# almost equivalent to x11-servers/xorg-server's
RUN_DEPENDS+=	${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config \
		xkbcomp:x11/xkbcomp

USES+=		autoreconf:build compiler:c11 gl jpeg libtool perl5 pkgconfig ssl shebangfix xorg
USE_LDCONFIG=	yes
USE_GL+=	gbm gl
USE_XORG+=	ice pixman sm x11 xau xdamage xdmcp xext xfixes xfont2 \
		xkbfile xorg-macros xorgproto xrandr xrender xtrans xtst

SHEBANG_FILES=	unix/vncserver/vncsession-start.in
BINARY_WRAPPERS=	gm4

OPTIONS_DEFINE=	DOCS GNUTLS PAM
OPTIONS_DEFAULT=	GNUTLS PAM
OPTIONS_SUB=	yes
GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS
GNUTLS_CONFIGURE_ARGS=	--enable-glx-tls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
PAM_CMAKE_BOOL=	ENABLE_PAM

CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} --mandir=${PREFIX}/share/man \
		--docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace \
		--disable-static --disable-dri --disable-unit-tests \
		--disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
		--disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
		--disable-config-dbus --disable-config-hal \
		--disable-dri2 --enable-install-libxf86config --enable-glx \
		--with-xkb-path=${LOCALBASE}/share/X11/xkb \
		--with-xkb-bin-directory=${LOCALBASE}/bin \
		--with-serverconfig-path=${LOCALBASE}/lib/X11 \
		--disable-selective-werror \
		--disable-xwayland \
		--with-fontrootdir=${LOCALBASE}/share/fonts

FONTPATH_ROOT?=	${LOCALBASE}/share/fonts
FONTPATHD?=	${PREFIX}/etc/X11/fontpath.d
DEFAULT_FONTPATH_LIST= \
	${FONTPATH_ROOT}/misc/  \
	${FONTPATH_ROOT}/TTF/ \
	${FONTPATH_ROOT}/OTF/ \
	${FONTPATH_ROOT}/Type1/ \
	${FONTPATH_ROOT}/100dpi/ \
	${FONTPATH_ROOT}/75dpi/ \
	catalogue:${FONTPATHD}
CONFIGURE_ARGS+=	--with-default-font-path="${DEFAULT_FONTPATH_LIST:ts,}"

CFLAGS+=	-I${LOCALBASE}/include/libdrm

# This is server port, disabling some features
# - disable vncviewer
# - server is not internationalized
CMAKE_ARGS+=	-DBUILD_VIEWER:BOOL=false -DENABLE_NLS:BOOL=false

# TIGERVNC_XOG_PATCH_VER will be 21 when xorg-server 21.1.13
TIGERVNC_XORG_PATCH_VER=	${MAKE} -C "${.CURDIR}/../../x11-servers/xorg-server" -V PORTVERSION:R:R
XORG_WRKSRC=	${MAKE} -C ${.CURDIR}/../../x11-servers/xorg-server -VWRKSRC

pre-patch:
	${CP} -R $$(${XORG_WRKSRC})/ ${WRKSRC}/unix/xserver/

post-patch:
	# do not build tests
	${REINPLACE_CMD} -e 's|add_subdirectory(tests)||' ${WRKSRC}/CMakeLists.txt
	cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver$$(${TIGERVNC_XORG_PATCH_VER}).patch

post-configure:
	cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${AUTORECONF} -fiv
	cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	cd ${WRKSRC}/unix/xserver/ && \
	    ${DO_MAKE_BUILD} SHELL=${LOCALBASE}/bin/bash ${ALL_TARGET}

post-stage:
	# Install v1.10.0 vncserver script and manpage.
	# See: https://cgit.freebsd.org/ports/commit/net/tigervnc-server?id=e6d3d07
	${INSTALL_SCRIPT} ${FILESDIR}/v1.10.0-vncserver ${STAGEDIR}${PREFIX}/bin/vncserver
	${INSTALL_MAN} ${FILESDIR}/v1.10.0-vncserver.man ${STAGEDIR}${PREFIX}/share/man/man8/vncserver.8

post-install:
	cd ${WRKSRC}/unix/xserver/hw/vnc/ && \
	    ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install-strip

.include "${.CURDIR}/Makefile.common.mk"

# import from x11-server/xorg-server/Makefile
.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't
# install a .pc file and configure will fail trying to find it.
# Setting both of those variables to a *non-empty* value by-passes
# the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

# keep in sync with all platforms where libunwind is available
.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == powerpc || ${ARCH} == powerpc64 || ${ARCH} == powerpc64le
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif
