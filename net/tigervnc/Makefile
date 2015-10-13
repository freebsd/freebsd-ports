# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	tigervnc
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net x11-servers

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	High-performance, platform-neutral implementation of VNC

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENCE.TXT

PATCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-servers/xorg-server:patch
BUILD_DEPENDS=	${LOCALBASE}/include/GL/internal/dri_interface.h:${PORTSDIR}/graphics/dri \
		${LOCALBASE}/libdata/pkgconfig/fontutil.pc:${PORTSDIR}/x11-fonts/font-util \
		bash:${PORTSDIR}/shells/bash
# almost equivalent to x11-servers/xorg-server's
RUN_DEPENDS=	${LOCALBASE}/share/X11/xkb/rules/base:${PORTSDIR}/x11/xkeyboard-config \
		xkbcomp:${PORTSDIR}/x11/xkbcomp

CONFLICTS=	tridiavnc-[0-9]* \
		tightvnc-[0-9]* \
		vnc-[0-9]*

USES=		autoreconf:build cmake cpe gmake libtool pkgconfig python
USE_GL=		gl
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	TigerVNC

USE_XORG+=	bigreqsproto compositeproto damageproto fixesproto fontsproto glproto \
		inputproto kbproto pixman randrproto renderproto resourceproto \
		scrnsaverproto videoproto xau xdmcp xext xkbfile xcmiscproto xextproto \
		xfont xproto xrandr xtrans xtst xorg-macros presentproto

CFLAGS+=	-fPIC

OPTIONS_DEFINE=		GNUTLS NLS PAM VIEWER HPJPG DOCS
OPTIONS_DEFAULT=	GNUTLS NLS PAM VIEWER
VIEWER_DESC=		Build vncviewer
HPJPG_DESC=		Build with High-Performance JPEG support

.include <bsd.port.options.mk>

CMAKE_ARGS=	-G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${STAGE}${PREFIX}

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--enable-glx-tls
CMAKE_ARGS+=	-DENABLE_GNUTLS=1
.else
CMAKE_ARGS+=	-DENABLE_GNUTLS=0
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CMAKE_ARGS+=	-DENABLE_NLS=1
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DENABLE_NLS=0
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DENABLE_PAM=1
.else
CMAKE_ARGS+=	-DENABLE_PAM=0
.endif

.if ${PORT_OPTIONS:MVIEWER}
CMAKE_ARGS+=	-DBUILD_VIEWER=1
LIB_DEPENDS+=	libpng.so:${PORTSDIR}/graphics/png \
		libfltk.so:${PORTSDIR}/x11-toolkits/fltk
# ImageMagick is required to generate icons during build process
BUILD_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
USE_XORG+=	xcursor xfixes xft xinerama
PLIST_SUB+=	VIEWER=""
INSTALLS_ICONS=	yes
DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
			"${PORTNAME}" "vncviewer" "Network;" false
.else
CMAKE_ARGS+=	-DBUILD_VIEWER=0
PLIST_SUB+=	VIEWER="@comment "
.endif

.if ${PORT_OPTIONS:MHPJPG}
LIB_DEPENDS+=	libturbojpeg.so:${PORTSDIR}/graphics/libjpeg-turbo
.else
USES+=		jpeg
.endif

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
		--with-fontrootdir=${LOCALBASE}/share/fonts

.include <bsd.port.pre.mk>

TIGERVNC_XORG_PATCH_VER=	117

# import from x11-server/xorg-server/Makefile
.ifdef WITH_OPENSSL_BASE
# The reason why I use this is cause openssl from base doesn't
# install a .pc file and configure will fail trying to find it.
# Setting both of those variables to a *non-empty* value by-passes
# the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

XORG_WRKDIR=	${MAKE} -C ${PORTSDIR}/x11-servers/xorg-server -VWRKSRC

pre-patch:
	@${CP} -R `${XORG_WRKDIR}`/ ${WRKSRC}/unix/xserver/

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver${TIGERVNC_XORG_PATCH_VER}.patch

post-configure:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/autoreconf -fiv
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} SHELL=${LOCALBASE}/bin/bash

post-install:
	@cd ${WRKSRC}/unix/xserver/hw/vnc/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install

.include <bsd.port.post.mk>
