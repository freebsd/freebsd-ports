# $FreeBSD$

PORTNAME=	tigervnc
PORTVERSION=	1.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	net x11-servers

MAINTAINER=	meta@FreeBSD.org
COMMENT=	High-performance, platform-neutral implementation of VNC

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

PATCH_DEPENDS=	${NONEXISTENT}:x11-servers/xorg-server:patch
BUILD_DEPENDS=	${LOCALBASE}/include/GL/internal/dri_interface.h:graphics/mesa-dri \
		${LOCALBASE}/libdata/pkgconfig/fontutil.pc:x11-fonts/font-util \
		${LOCALBASE}/include/FL/Fl.H:x11-toolkits/fltk \
		bash:shells/bash
LIB_DEPENDS=	libxshmfence.so:x11/libxshmfence \
		libfontconfig.so:x11-fonts/fontconfig
# almost equivalent to x11-servers/xorg-server's
RUN_DEPENDS=	${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config \
		xkbcomp:x11/xkbcomp

USES=		autoreconf:build cmake:insource,noninja cpe gl iconv jpeg libtool \
		pkgconfig python ssl
USE_GL=		gl
USE_LDCONFIG=	yes
USE_GITHUB=	yes

CONFLICTS=	tightvnc-[0-9]*

GH_ACCOUNT=	TigerVNC

USE_XORG+=	ice pixman sm x11 xau xdamage xdmcp xext xfixes xfont xkbfile \
		xorg-macros xorgproto xrandr xrender xtrans xtst

OPTIONS_DEFINE=		GNUTLS NLS PAM VIEWER DOCS
OPTIONS_DEFAULT=	GNUTLS PAM VIEWER
OPTIONS_SUB=		yes
VIEWER_DESC=		Build vncviewer

GNUTLS_CMAKE_BOOL=	ENABLE_GNUTLS
GNUTLS_CONFIGURE_ARGS=	--enable-glx-tls
GNUTLS_LIB_DEPENDS=	libtasn1.so:security/libtasn1 \
			libgcrypt.so:security/libgcrypt \
			libgpg-error.so:security/libgpg-error \
			libgnutls.so:security/gnutls
PAM_CMAKE_BOOL=	ENABLE_PAM
VIEWER_CMAKE_BOOL=	BUILD_VIEWER
VIEWER_BUILD_DEPENDS=	convert:graphics/ImageMagick7 # to generate icons during build
VIEWER_LIB_DEPENDS=	libpng.so:graphics/png \
			libfltk.so:x11-toolkits/fltk
VIEWER_INSTALLS_ICONS=	yes
VIEWER_DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
				"${PORTNAME}" "vncviewer" "Network;" false
VIEWER_USE=	xorg=xcursor,xfixes,xft,xinerama
NLS_CMAKE_BOOL=	ENABLE_NLS
NLS_USES=	gettext

CMAKE_ARGS+=	-G "Unix Makefiles"
MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} --mandir=${PREFIX}/man/ \
		--docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace \
		--disable-static --disable-dri --disable-unit-tests \
		--disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
		--disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
		--disable-config-dbus --disable-config-hal \
		--disable-dri2 --enable-install-libxf86config --enable-glx \
		--with-default-font-path="catalogue:${LOCALBASE}/share/fonts,built-ins" \
		--with-xkb-path=${LOCALBASE}/share/X11/xkb \
		--with-xkb-bin-directory=${LOCALBASE}/bin \
		--with-serverconfig-path=${LOCALBASE}/lib/X11 \
		--disable-selective-werror \
		--disable-xwayland \
		--with-fontrootdir=${LOCALBASE}/share/fonts

.include <bsd.port.pre.mk>

# keep in sync with all platforms where libunwind is available
.if (${ARCH} == amd64 || ${ARCH} == i386)
LIB_DEPENDS+=	libunwind.so:devel/libunwind
.endif

TIGERVNC_XORG_PATCH_VER=	${MAKE} -C "${.CURDIR}/../../x11-servers/xorg-server" -V PORTVERSION:R:S,\.,,g
XORG_WRKSRC=	${MAKE} -C ${.CURDIR}/../../x11-servers/xorg-server -VWRKSRC

# import from x11-server/xorg-server/Makefile
.if ${SSL_DEFAULT} == base
# The reason why I use this is cause openssl from base doesn't
# install a .pc file and configure will fail trying to find it.
# Setting both of those variables to a *non-empty* value by-passes
# the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

pre-patch:
	@${CP} -R $$(${XORG_WRKSRC})/ ${WRKSRC}/unix/xserver/

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver$$(${TIGERVNC_XORG_PATCH_VER}).patch

post-configure:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${AUTORECONF} -fiv
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SHELL=${LOCALBASE}/bin/bash

post-install:
	@cd ${WRKSRC}/unix/xserver/hw/vnc/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/Xvnc ${STAGEDIR}${PREFIX}/lib/xorg/modules/extensions/libvnc.so

.include <bsd.port.post.mk>
