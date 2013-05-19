# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	tigervnc
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	net x11-servers
MASTER_SITES=	SF:tigervnc
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTVERSION}/:tigervnc
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz:tigervnc

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	TigerVNC is an advanced VNC implementation

LISENCE=	GPLv2
LISENCE_FILE=	${WRKSRC}/LICENCE.TXT

PATCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/x11-servers/xorg-server:patch
# almost equivalent to x11-servers/xorg-server's
RUN_DEPENDS=	${LOCALBASE}/share/X11/xkb/rules/base:${PORTSDIR}/x11/xkeyboard-config \
		xkbcomp:${PORTSDIR}/x11/xkbcomp

CONFLICTS=	tridiavnc-[0-9]* \
		tightvnc-[0-9]* \
		vnc-[0-9]*

MAKE_JOBS_UNSAFE=	yes

USES=		cmake pkgconfig
USE_GMAKE=	yes
USE_GL=		gl
USE_AUTOTOOLS+=	autoconf:env automake:env libtool:env
USE_PYTHON=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes

USE_XORG+=	bigreqsproto compositeproto damageproto fixesproto fontsproto glproto \
		inputproto kbproto pixman randrproto renderproto resourceproto \
		scrnsaverproto videoproto xau xdmcp xext xkbfile xcmiscproto xextproto \
		xfont xproto xrandr xtrans xtst xorg-macros

MAN1+=		vncpasswd.1 \
		x0vncserver.1 \
		vncserver.1 \
		vncconfig.1 \
		Xvnc.1
CFLAGS+=	-fPIC

OPTIONS_DEFINE=		GNUTLS NLS PAM VIEWER HPJPG
OPTIONS_DEFAULT=	GNUTLS NLS PAM VIEWER
VIEWER_DESC=		Build vncviewer
HPJPG_DESC=		Build with High-Performance JPEG support

.include <bsd.port.options.mk>

CMAKE_ARGS=	-G "Unix Makefiles" -DCMAKE_INSTALL_PREFIX=${PREFIX}

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	tasn1:${PORTSDIR}/security/libtasn1 \
		gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		gnutls:${PORTSDIR}/security/gnutls
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
CMAKE_ARGS+=	-DENABLE_VIEWER=1
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png \
		fltk:${PORTSDIR}/x11-toolkits/fltk
USE_XORG+=	xcursor xfixes xft xinerama
MAN1+=		vncviewer.1
PLIST_SUB+=	VIEWER=""
INSTALLS_ICONS=	yes
DESKTOP_ENTRIES=	"TigerVNC viewer" "Connect to VNC server and display remote desktop" \
			"${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg" \
			"vncviewer" "Network;" false
.else
PLIST_SUB+=	VIEWER="@comment "
.endif

.if ${PORT_OPTIONS:MHPJPG}
LIB_DEPENDS+=	turbojpeg:${PORTSDIR}/graphics/libjpeg-turbo
.else
LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg
.endif

MAKE_ARGS+=	TIGERVNC_SRCDIR=${WRKSRC}
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} --mandir=${PREFIX}/man/ \
		--docdir=${PREFIX}/share/doc/${PORTNAME}/ --with-pic --without-dtrace \
		--disable-static --disable-dri \
		--disable-xinerama --disable-xvfb --disable-xnest --disable-xorg \
		--disable-dmx --disable-xwin --disable-xephyr --disable-kdrive \
		--disable-config-dbus --disable-config-hal \
		--disable-dri2 --enable-install-libxf86config --enable-glx \
		--with-default-font-path="catalogue:${PREFIX}/share/fonts,built-ins" \
		--with-fontdir=${PREFIX}/share/fonts \
		--with-xkb-path=${PREFIX}/share/X11/xkb \
		--with-xkb-output=/var/lib/xkb \
		--with-xkb-bin-directory=${PREFIX}/bin \
		--with-serverconfig-path=${PREFIX}/lib/X11 \
		--disable-selective-werror

.include <bsd.port.pre.mk>

.ifdef WITH_NEW_XORG
TIGERVNC_XORG_PATCH_VER=	110
.else
TIGERVNC_XORG_PATCH_VER=	17
.endif

# import from x11-server/xorg-server/Makefile
.ifdef WITH_OPENSSL_BASE
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

XORG_WRKDIR=	${MAKE} -C ${PORTSDIR}/x11-servers/xorg-server -VWRKSRC

pre-patch:
	@${CP} -R `${XORG_WRKDIR}`/ ${WRKSRC}/unix/xserver/

post-patch:
	@cd ${WRKSRC}/unix/xserver/ && ${PATCH} -p1 < ${WRKSRC}/unix/xserver${TIGERVNC_XORG_PATCH_VER}.patch

post-configure:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ${AUTORECONF} -fiv
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}

post-build:
	@cd ${WRKSRC}/unix/xserver/ && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS}

post-install:
	@cd ${WRKSRC}/unix/xserver/hw/vnc/ && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_ARGS} install
.if ${PORT_OPTIONS:MVIEWER}
	@${MKDIR} ${PREFIX}/share/icons/hicolor/scalable/apps/
	@cd ${WRKSRC}/media/ && ${INSTALL_DATA} icons/tigervnc.svg ${PREFIX}/share/icons/hicolor/scalable/apps/
.endif

.include <bsd.port.post.mk>
