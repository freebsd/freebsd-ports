# New ports collection makefile for:    XFree86-Server
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.4.0
PORTREVISION=	7
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-1.tgz:x \
		XFree86-4.4.0-src-2.tgz:x \
		XFree86-4.4.0-src-3.tgz:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	XFree86-4.4.0-src-1.tgz \
		XFree86-4.4.0-src-2.tgz \
		XFree86-4.4.0-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 X server and related programs

CONFLICTS=	xorg-server-[0-9]*

# Override default from XFree86-4-libraries/Makefile.inc
PATCHDIR=		${MASTERDIR}/files

.for pf in patch-Imake.rules patch-Imake.tmpl \
			patch-X11.tmpl patch-Xcursor-Imakefile \
			patch-amd64 patch-c2 patch-dri-Imakefile \
			patch-f patch-imake.c \
			patch-texteroids patch-xditview-Imakefile patch-xdm \
			patch-xdm_session.c patch-xf86.tmpl \
			patch-xterm-Imakefile patch-z05 patch-z14 \
			patch-z15 patch-z30 patch-z32 patch-z34 patch-z35 \
			patch-z41 patch-z44 patch-z45
# patch-startx

EXTRA_PATCHES+=		${.CURDIR}/../../x11/XFree86-4-libraries/files/${pf}
.endfor

SCRIPTS_ENV=		OSVERSION=${OSVERSION} \
			BuildXF86DRI=${BuildXF86DRI} \
			WITH_DEBUG="${WITH_DEBUG}"
MAN1=			XFree86.1 \
			Xserver.1 \
			getconfig.1 \
			gtf.1 \
			kbd_mode.1 \
			pcitweak.1 \
			xf86cfg.1 \
			xf86config.1
MAN3=			XF86VidMode.3 \
			XF86VidModeDeleteModeLine.3 \
			XF86VidModeGetAllModeLines.3 \
			XF86VidModeGetDotClocks.3 \
			XF86VidModeGetGamma.3 \
			XF86VidModeGetGammaRamp.3 \
			XF86VidModeGetGammaRampSize.3 \
			XF86VidModeGetModeLine.3 \
			XF86VidModeGetMonitor.3 \
			XF86VidModeGetPermissions.3 \
			XF86VidModeGetViewPort.3 \
			XF86VidModeLockModeSwitch.3 \
			XF86VidModeModModeLine.3 \
			XF86VidModeQueryExtension.3 \
			XF86VidModeQueryVersion.3 \
			XF86VidModeSetClientVersion.3 \
			XF86VidModeSetGamma.3 \
			XF86VidModeSetGammaRamp.3 \
			XF86VidModeSetViewPort.3 \
			XF86VidModeSwitchMode.3 \
			XF86VidModeSwitchToMode.3 \
			XF86VidModeValidateModeLine.3
MAN4=			citron.4x \
			dynapro.4x \
			elographics.4x \
			fbdevhw.4x \
			kbd.4x \
			keyboard.4x \
			microtouch.4x \
			mouse.4x \
			mutouch.4x \
			nv.4x \
			r128.4x \
			radeon.4x \
			void.4x \
			wacom.4x
MAN5=			XF86Config.5 \
			getconfig.5
PKGMESSAGE=		${WRKDIR}/.pkg-message
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

NOT_FOR_ARCHS=		ia64

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif

.if ${ARCH} == i386 || ${ARCH} == alpha || ${ARCH} == amd64
RUN_DEPENDS+=		${X11BASE}/lib/modules/dri/r200_dri.so:${PORTSDIR}/graphics/xfree86-dri
BuildXF86DRI=		YES
PLIST_SUB+=		DRI=""
.else
BuildXF86DRI=		NO
PLIST_SUB+=		DRI="@comment "
.endif

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
MAN4+=		cirrus.4x
.else
PLIST_SUB+=	ALPHA_NA=""
.endif

.if ${ARCH} == amd64
PLIST_SUB+=	AMD64_NA="@comment "
PLIST_SUB+=	AMD64=""
MAN4+=		apm.4x \
		chips.4x \
		cirrus.4x \
		cyrix.4x \
		fbdev.4x \
		i128.4x \
		neomagic.4x \
		sis.4x \
		trident.4x \
		tseng.4x \
		vesa.4x
.else
PLIST_SUB+=	AMD64_NA=""
PLIST_SUB+=	AMD64="@comment "
.endif

.if ${ARCH} == ia64
PLIST_SUB+=	IA64_NA="@comment "
.else
PLIST_SUB+=	IA64_NA=""
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64_NA="@comment "
PLIST_SUB+=	SPARC64=""
MAN4+=		sunffb.4x
.else
PLIST_SUB+=	SPARC64="@comment "
PLIST_SUB+=	SPARC64_NA=""
MAN4+=		glint.4x \
		mga.4x \
		rendition.4x \
		s3virge.4x \
		savage.4x \
		siliconmotion.4x \
		tdfx.4x \
		vga.4x
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
MAN1+=		scanpci.1
MAN4+=		apm.4x \
		chips.4x \
		cirrus.4x \
		cyrix.4x \
		i128.4x \
		i740.4x \
		i810.4x \
		neomagic.4x \
		nsc.4x \
		sis.4x \
		trident.4x \
		tseng.4x \
		vesa.4x \
		via.4x \
		vmware.4x
.else
PLIST_SUB+=	I386="@comment "
.endif

.if ${ARCH} == i386 || ${ARCH} == amd64
PLIST_SUB+=	AMD64_I386=""
.else
PLIST_SUB+=	AMD64_I386="@comment "
.endif

post-extract::
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c
	@${MKDIR} ${WRKDIR}/drmsource

post-build:
	@${RM} -f ${PKGMESSAGE}
	@${CAT} ${.CURDIR}/pkg-message >> ${PKGMESSAGE}

post-install::
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} -e s,/usr/X11R6,${PREFIX}, ${PKGMESSAGE}
	@if [ -f ${PREFIX}/bin/Xwrapper-4 ] ; then \
	${LN} -sf Xwrapper-4 ${PREFIX}/bin/X; \
	fi;

.include <bsd.port.post.mk>
