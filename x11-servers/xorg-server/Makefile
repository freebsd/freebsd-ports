# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	server
PORTVERSION=	6.7.0
PORTREVISION=	5
CATEGORIES=	x11-servers
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
PKGNAMEPREFIX=	xorg-
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src3.tar.gz

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
MAN4=		citron.4 \
		dynapro.4 \
		elographics.4 \
		fbdevhw.4 \
		kbd.4 \
		keyboard.4 \
		microtouch.4 \
		mouse.4 \
		mutouch.4 \
		nv.4 \
		r128.4 \
		radeon.4 \
		void.4 \
		wacom.4
MAN5=		xorg.conf.5

XBUILD_DIRS=	lib/font programs/Xserver
XINCLUDE_DIRS=	lib/xtrans
XMAN_DIRS=	programs/Xserver

NOT_FOR_ARCHS=	ia64
.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org
.endif

.if ${ARCH} == ia64
PLIST_SUB+=	IA64_NA="@comment "
.else
PLIST_SUB+=	IA64_NA=""
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64=""
PLIST_SUB+=	SPARC64_NA="@comment "
MAN4+=		sunffb.4
.else
PLIST_SUB+=	SPARC64="@comment "
PLIST_SUB+=	SPARC64_NA=""
MAN4+=		glint.4 \
		mga.4 \
		rendition.4 \
		s3virge.4 \
		savage.4 \
		siliconmotion.4 \
		sis.4 \
		tdfx.4 \
		vga.4
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
MAN1+=		scanpci.1
MAN4+=		apm.4 \
		chips.4 \
		cirrus.4 \
		cyrix.4 \
		i128.4 \
		i740.4 \
		i810.4 \
		neomagic.4 \
		nsc.4 \
		trident.4 \
		tseng.4 \
		vesa.4 \
		vmware.4
.else
PLIST_SUB+=	I386="@comment "
.endif

.if !defined(NO_SUID_XSERVER) || ${NO_SUID_XSERVER} == NO
pre-everything::
	@${ECHO_MSG} "By default, the X Server installs as a set-user-id root binary. When run by"
	@${ECHO_MSG} "a normal user, it checks arguments and environment as done in the x11/wrapper"
	@${ECHO_MSG} "port before handling them normally.  If you are concerned about the security"
	@${ECHO_MSG} "of this, but still want to run an X Server (for example using xdm/kdm/gdm, which"
	@${ECHO_MSG} "will still run the server as root), you can cancel the build and set"
	@${ECHO_MSG} "NO_SUID_XSERVER=YES in /etc/make.conf."

SCRIPTS_ENV+=	SUID_XSERVER=YES
.else
SCRIPTS_ENV+=	SUID_XSERVER=NO
.endif

.include <bsd.port.post.mk>
