# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-server
PORTVERSION=	6.9.0
PORTREVISION=	3
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X.Org X server and related programs

.if !defined(WITH_MODULAR)
USE_XLIB=	yes
.else
LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp \
		${X11BASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		GL.1:${PORTSDIR}/x11/libGL
BUILD_DEPENDS=	${X11BASE}/include/X11/extensions/XKMformat.h:${PORTSDIR}/x11/libxkbfile \
		${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}
.endif

CONFLICTS=	XFree86-Server-*

SCRIPTS_ENV=	WITH_DEBUG="${WITH_DEBUG}"
MAN1=		Xorg.1 \
		getconfig.1 \
		gtf.1 \
		kbd_mode.1 \
		pcitweak.1 \
		xorgcfg.1 \
		xorgconfig.1
MAN4=		citron.4x \
		dmc.4x \
		dynapro.4x \
		elographics.4x \
		fbdevhw.4x \
		fpit.4x \
		glint.4x \
		js_x.4x \
		kbd.4x \
		keyboard.4x \
		mga.4x \
		microtouch.4x \
		mouse.4x \
		mutouch.4x \
		palmax.4x \
		penmount.4x \
		r128.4x \
		radeon.4x \
		tdfx.4x \
		tek4957.4x \
		vga.4x \
		void.4x \
		wacom.4x
MAN5=		getconfig.5 \
		xorg.conf.5

XBUILD_DIRS=	lib/font programs/Xserver
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/Xserver

NOT_FOR_ARCHS=	ia64
.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org and you have ${X_WINDOW_SYSTEM} set for X11\
	distribution. See The X Window System and Virtual Consoles chapter\
	of FAQ for more information
.endif

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
.endif
		
.if ${ARCH} == ia64
PLIST_SUB+=	IA64_NA="@comment "
.else
PLIST_SUB+=	IA64_NA=""
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
MAN4+=		sunbw2.4x \
		suncg14.4x \
		suncg3.4x \
		suncg6.4x \
		sunffb.4x \
		sunleo.4x \
		suntcx.4x
.else
PLIST_SUB+=	SPARC64="@comment "
PLIST_SUB+=	SPARC64_NA=""
.endif

.if ${ARCH} != powerpc && ${ARCH} != sparc64
MAN4+=		cirrus.4x \
		nv.4x \
		rendition.4x \
		s3virge.4x \
		savage.4x \
		siliconmotion.4x
.endif

.if ${ARCH} != powerpc && ${ARCH} != alpha
MAN4+=		vesa.4x
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
MAN1+=		scanpci.1
MAN4+=		i740.4x \
		nsc.4x \
		via.4x
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
PLIST_SUB+=	AMD64_I386=""
MAN4+=		apm.4x \
		chips.4x \
		cyrix.4x \
		i128.4x \
		i810.4x \
		neomagic.4x \
		sis.4x \
		trident.4x \
		tseng.4x \
		vmware.4x
.else
PLIST_SUB+=	AMD64_I386="@comment "
.endif

.if !defined(NO_SUID_XSERVER) || ${NO_SUID_XSERVER} == NO
pre-everything::
	@${ECHO_MSG} "By default, the X Server installs as a set-user-id root binary. When run by"
	@${ECHO_MSG} "a normal user, it checks arguments and environment as done in the x11/wrapper"
	@${ECHO_MSG} "port before handling them normally.  If you are concerned about the security"
	@${ECHO_MSG} "of this, but still want to run an X Server (for example using xdm/kdm/gdm,"
	@${ECHO_MSG} "which will still run the server as root), you can cancel the build and set"
	@${ECHO_MSG} "NO_SUID_XSERVER=YES in /etc/make.conf."

SCRIPTS_ENV+=	SUID_XSERVER=YES
.else
SCRIPTS_ENV+=	SUID_XSERVER=NO
.endif

.include <bsd.port.post.mk>
