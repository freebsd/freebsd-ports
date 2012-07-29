# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME?=	xorg-server
PORTVERSION=	${XORG_VERSION}
PORTREVISION?=	${XORG_REVISION}
PORTEPOCH?=	1
CATEGORIES=	x11-servers
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/
DISTFILES=	xorg-server-${PORTVERSION}.tar.bz2

MAINTAINER=	x11@FreeBSD.org
COMMENT?=	X.Org X server and related programs

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm

RUN_DEPENDS=	${LOCALBASE}/share/X11/xkb/rules/base.xml:${PORTSDIR}/x11/xkeyboard-config \
		xkbcomp:${PORTSDIR}/x11/xkbcomp

XORG_CAT=	xserver

.if defined(WITH_NEW_XORG)
XORG_VERSION=	1.10.6
XORG_REVISION=	0
PLIST_SUB+=	OLD="@comment " NEW=""
EXTRA_PATCHES+=	${FILESDIR}/extra-hw_dmx_glxProxy_compsize.h \
		${FILESDIR}/extra-hw_dmx_glxProxy_glxcmds.h
.else
XORG_VERSION=	1.7.7
XORG_REVISION=	5
PLIST_SUB+=	OLD="" NEW="@comment "
EXTRA_PATCHES+=	${FILESDIR}/extra-dix_events.c
EXTRA_PATCHES+=	${FILESDIR}/extra-include_eventstr.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-os-utils.c
.endif

USE_GMAKE=	yes
USE_GL=		gl
USE_XORG?=	xf86driproto glproto xdmcp x11 xkbfile xxf86misc xxf86vm xaw7 \
		xmu xt xpm xext randrproto renderproto fixesproto damageproto \
		dri2proto xcmiscproto xextproto xproto xtrans xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto inputproto xf86dgaproto \
		videoproto compositeproto trapproto recordproto xineramaproto \
		xinerama evieproto xfont fontenc xkbui pixman pciaccess

MAKE_JOBS_UNSAFE=	yes
USE_OPENSSL=	yes
USE_PERL5_BUILD=yes
CONFIGURE_ARGS?=--disable-dmx --disable-xvfb --disable-xnest \
		--without-xmlto --disable-docs --disable-devel-docs \
		--localstatedir=/var --without-dtrace --disable-xephyr \
		--enable-record=yes

.if !defined(SLAVE_PORT)
MAN1=		Xorg.1 \
		Xserver.1 \
		cvt.1 \
		gtf.1
MAN4=		exa.4 \
		fbdevhw.4
MAN5=		xorg.conf.5

.if (WITH_NEW_XORG)
MAN5+=		xorg.conf.d.5
.endif
.else
# for slave ports we need to overwrite PLIST, so it doesn't overwrite
# PLIST_FILES, with the masterport plist.
PLIST=		${.CURDIR}/pkg-plist
.endif

OPTIONS_DEFINE=	AIGLX SUID HAL
AIGLX_DESC=	Compile with Accelerated Indirect GLX support
SUID_DESC=	Install the Xorg server with setuid bit set
HAL_DESC=	Compile with HAL config support
OPTIONS_DEFAULT=	AIGLX SUID HAL

OPTIONS_EXCLUDE_sparc64=	HAL

.include <bsd.port.pre.mk>

.if defined(WITH_OPENSSL_BASE)
# The reason why I use this is cause openssl from base doesn't install a .pc file
# and configure will fail trying to find it. Setting both of those variables to
# a *non-empty* value by-passes the pkg-config check.
CONFIGURE_ENV=	SHA1_LIB="-L/usr/lib -lcrypto" SHA1_CFLAGS="-I/usr/include"
.endif

.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
CONFIGURE_ARGS+=	--enable-config-hal=yes
.else
CONFIGURE_ARGS+=	--enable-config-hal=no
.endif

.if ${PORT_OPTIONS:MAIGLX}
CONFIGURE_ARGS+=	--enable-aiglx=yes
.else
CONFIGURE_ARGS+=	--enable-aiglx=no
.endif

.if ${PORT_OPTIONS:MSUID}
CONFIGURE_ARGS+=--enable-install-setuid=yes
.else
CONFIGURE_ARGS+=--enable-install-setuid=no
.endif

.if ${ARCH} == ia64
PLIST_SUB+=     IA64_NA="@comment "
EXTRA_PATCHES=  ${.CURDIR}/files/extra-arch-ia64
.else
PLIST_SUB+=     IA64_NA=""
.endif

.if ${ARCH} == powerpc || ${ARCH} == powerpc64
PLIST_SUB+=	PPC_NA="@comment "
EXTRA_PATCHES=	${.CURDIR}/files/extra-arch-powerpc
.else
PLIST_SUB+=	PPC_NA=""
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
PLIST_SUB+=	SPARC64_NA="@comment "
.else
PLIST_SUB+=	SPARC64="@comment "
PLIST_SUB+=	SPARC64_NA=""
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386 || ${ARCH} == sparc64
PLIST_SUB+=	AMD64_I386_SPARC64=""
.else
PLIST_SUB+=	AMD64_I386_SPARC64="@comment "
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

.if defined(WITH_NEW_XORG)
post-install:
	@${MKDIR} ${PREFIX}/share/X11/xorg.conf.d

PLIST_SUB+=	OLD="@comment " NEW=""
.else
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

.include <bsd.port.post.mk>
