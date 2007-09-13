# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-server
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	x11-servers
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/xserver/:fdo \
		${MASTER_SITE_SOURCEFORGE:S/$/:mesa/}
MASTER_SITE_SUBDIR=mesa3d/:mesa
DISTFILES=	xorg-server-${PORTVERSION}.tar.bz2:fdo \
		MesaLib-7.0.1.tar.bz2:mesa

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X server and related programs

LIB_DEPENDS=	drm:${PORTSDIR}/graphics/libdrm
RUN_DEPENDS=	${X11BASE}/share/X11/xkb/rules/base.xml:${PORTSDIR}/x11/xkeyboard-config

CONFLICTS=	XFree86-Server-*

XORG_CAT=	xserver

USE_XORG=	xf86driproto glproto xdmcp x11 xkbfile xxf86misc xxf86vm xaw7 \
		xmu xt xpm xext randrproto renderproto fixesproto damageproto \
		xcmiscproto xextproto xproto xtrans xf86miscproto \
		xf86vidmodeproto xf86bigfontproto scrnsaverproto bigreqsproto \
		resourceproto fontsproto inputproto xf86dgaproto \
		videoproto compositeproto trapproto recordproto xineramaproto \
		evieproto xfont fontenc xkbui pixman

USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--with-mesa-source=${WRKDIR}/Mesa-7.0.1 \
		--disable-dmx --disable-xvfb --disable-xnest --disable-xprint \
		--localstatedir=/var

.if !defined(WITHOUT_HAL)
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=	--disable-config-hal
.endif

.if !defined(WITHOUT_AIGLX)
CONFIGURE_ARGS+=	--enable-aiglx=yes
.endif
		
.if !defined(NO_SUID_XSERVER) || ${NO_SUID_XSERVER} == NO
CONFIGURE_ARGS+=--enable-install-setuid
.endif

MAN1=		Xorg.1 \
		Xserver.1 \
		cvt.1 \
		gtf.1 \
		pcitweak.1 \
		xorgconfig.1
MAN4=		exa.4 \
		fbdevhw.4
MAN5=		xorg.conf.5 \
		SecurityPolicy.5

NOT_FOR_ARCHS=	ia64
.include <bsd.port.pre.mk>

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
.endif

.if ${ARCH} == powerpc
PLIST_SUB+=	PPC_NA="@comment "
MAN4+=		nv.4x
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

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	AMD64_I386=""
MAN1+=		scanpci.1
.else
PLIST_SUB+=	AMD64_I386="@comment "
.endif

.if ${OSVERSION} > 700042
CFLAGS+=	-O0
.endif

.if !defined(NO_SUID_XSERVER) || ${NO_SUID_XSERVER} == NO
pre-everything::
	@${ECHO_MSG} "By default, the X Server installs as a set-user-id root binary. When run by"
	@${ECHO_MSG} "a normal user, it checks arguments and environment as done in the x11/wrapper"
	@${ECHO_MSG} "port before handling them normally.  If you are concerned about the security"
	@${ECHO_MSG} "of this, but still want to run an X Server (for example using xdm/kdm/gdm,"
	@${ECHO_MSG} "which will still run the server as root), you can cancel the build and set"
	@${ECHO_MSG} "NO_SUID_XSERVER=YES in /etc/make.conf."
.endif

#post-patch:
#	${ECHO_CMD} "XXX - Remove post-patch target!"
#	${REINPLACE_CMD} -e 's|pixman|pixman-1|' ${WRKSRC}/configure
#	${REINPLACE_CMD} -e 's|pixman/pixman.h|pixman.h|' \
#		${WRKSRC}/fb/fb.h \
#		${WRKSRC}/include/miscstruct.h \
#		${WRKSRC}/mi/miregion.c \
#		${WRKSRC}/render/picture.h
#	${CP} ${FILESDIR}/GL-glx-glxbyteorder.h ${WRKSRC}/GL/glx/glxbyteorder.h

.include <bsd.port.post.mk>
