# New ports collection makefile for:	XFree86-Server
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.1.0
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X410src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
SCRIPTS_ENV=		OSVERSION=${OSVERSION} \
			HasXdmAuth=${HasXdmAuth} \
			HasSecureRPC=${HasSecureRPC} \
			HasPam=${HasPam} \
			ExtendedInputDevices=${ExtendedInputDevices} \
			BuildXF86DRI=${BuildXF86DRI} \
			BuildXF86DRM=${BuildXF86DRM} \
			HaveMatroxHal=${HaveMatroxHal}
MAKE_ENV=		MAN_INSTALL_TARGET=FreeBSDPortsInstall.man WORLDOPTS=
MAKE_ARGS=		WORLDOPTS=
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET=		FreeBSDPortsInstall  FreeBSDPortsInstall.man
MAN1=			XFree86.1 \
			Xserver.1 \
			kbd_mode.1 \
			pcitweak.1 \
			scanpci.1 \
			xf86cfg.1 \
			xf86config.1
MAN3=			XF86VidMode.3 \
			XF86VidModeDeleteModeLine.3 \
			XF86VidModeGetAllModeLines.3 \
			XF86VidModeGetModeLine.3 \
			XF86VidModeGetMonitor.3 \
			XF86VidModeGetViewPort.3 \
			XF86VidModeLockModeSwitch.3 \
			XF86VidModeModModeLine.3 \
			XF86VidModeQueryExtension.3 \
			XF86VidModeQueryVersion.3 \
			XF86VidModeSetViewPort.3 \
			XF86VidModeSwitchMode.3 \
			XF86VidModeSwitchToMode.3
MAN4=			mga.4 \
			tdfx.4 \
			glint.4 \
			s3virge.4 \
			rendition.4 \
			savage.4 \
			nv.4 \
			siliconmotion.4 \
			vga.4 \
			vmware.4 \
			keyboard.4 \
			mouse.4
MAN5=			XF86Config.5
PKGMESSAGE=		${WRKDIR}/.pkg-message

.include <bsd.port.pre.mk>

# XFree86 User Config:
# ---
# Name          Default		Meaning
# ----------------------------------------------------------------------------
# HasXdmAuth	YES		support XDM-AUTHORIZATION-1.
# HasSecureRPC	YES		build with SecureRPC (require FreeBSD-3 or later)
# HasPam	YES		support PAM (require FreeBSD-3.1 or later)
# ExtendedInputDevices	YES	support extended input devices
HasXdmAuth?=		DEFAULT
HasSecureRPC?=		DEFAULT
HasPam?=		DEFAULT
ExtendedInputDevices?=	DEFAULT
.if !defined(I_WANT_TO_FIX_BUILDING_DRI_MODULES)
BuildXF86DRI=		NO
BuildXF86DRM=		NO
PLIST_SUB+=		DRI="@comment "
.else
.if ${OSVERSION} < 500013 && ${MACHINE} != alpha
.if (exists(/sys) || exists(/usr/src/sys))
BuildXF86DRI=		YES
BuildXF86DRM=		YES
PLIST_SUB+=		DRI=""
.else
_pre-fetch::
	@${ECHO_MSG} "DRI would not build: kernel source required in /sys."
.endif	# have /sys
.else
BuildXF86DRI=		NO
BuildXF86DRM=		NO
PLIST_SUB+=		DRI="@comment "
_pre-fetch::
	@${ECHO_MSG} "DRI would not build: incompatible with SMPng and alpha"
.endif	# PRE_SMPNG && !alpha
.endif	# DRI is totally broken

.if ${ARCH} == i386
PLIST_SUB+=	I386:=""
MAN4+=		apm.4 \
		chips.4 \
		cirrus.4 \
		cyrix.4 \
		fbdev.4 \
		fbdevhw.4 \
		i128.4 \
		i740.4 \
		i810.4 \
		neomagic.4 \
		r128.4 \
		sis.4 \
		trident.4 \
		tseng.4 \
		vesa.4
.else
PLIST_SUB+=	I386:="@comment "
.endif

.if ${ExtendedInputDevices} == DEFAULT || ${ExtendedInputDevices} == YES
PLIST_SUB+=	XIE:=""
MAN4+=		citron.4 \
		dynapro.4 \
		elographics.4 \
		microtouch.4 \
		mutouch.4 \
		wacom.4 \
		void.4
.else
PLIST_SUB+=	XIE:="@comment "
.endif

.if !defined(INCOMPATIBLE_WITH_4_1_0)
.if !defined(WITH_MATROX_GXX_DRIVER)
HaveMatroxHal=		NO
PLIST_SUB+=		MATROX="@comment "
_pre-fetch::
	@${ECHO_MSG} "Define WITH_MATROX_GXX_DRIVER to enable the official Matrox drivers for"
	@${ECHO_MSG} "the G200, G400 and G450 graphic adapters."
.else
HaveMatroxHal=		YES
MGA_DRIVER_VERSION=	1_2_0beta
MASTER_SITES+=		ftp://ftp.matrox.com/pub/mga/archive/linux/2001/beta_${MGA_DRIVER_VERSION:S/beta//}/
DISTFILES+=		mga-${MGA_DRIVER_VERSION}.tgz
EXTRACT_ONLY=		X410src-1.tgz
PLIST_SUB+=		MATROX=""
post-patch::
	@${MV} ${WRKSRC}/programs/Xserver/hw/xfree86/drivers/mga \
		${WRKSRC}/programs/Xserver/hw/xfree86/drivers/mga.old
	@${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/mga-${MGA_DRIVER_VERSION}.tgz \
		-C ${WRKSRC}/programs/Xserver/hw/xfree86/drivers
.endif	# !WITH_MATROX_GXX_DRIVER
.endif	# INCOMPATIBLE_WITH_4_1_0

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.if ${BuildXF86DRM} == "YES"
pre-install:
	${MKDIR} ${PREFIX}/lib/X11/kernel
.endif

post-build:
	@${RM} -f ${PKGMESSAGE}
.if ${BuildXF86DRM} == "YES"
	@${CAT} ${.CURDIR}/pkg-message-drm > ${PKGMESSAGE}
.endif
	@${CAT} ${.CURDIR}/pkg-message >> ${PKGMESSAGE}

post-install:
	@${SED} -e s,/usr/X11R6,${PREFIX}, ${PKGMESSAGE}
	strip ${PREFIX}/bin/XFree86

.include <bsd.port.post.mk>
