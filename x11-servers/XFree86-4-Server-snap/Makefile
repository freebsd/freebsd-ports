# New ports collection makefile for:	XFree86XServer-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.0.3
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.0.2
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X402src-1.tgz

PATCH_SITES=	${MASTER_SITE_XFREE:S,%SUBDIR%/source,4.0.3/patches,g}
PATCHFILES=	4.0.2-4.0.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
SCRIPTS_ENV=		HasXdmAuth=${HasXdmAuth} \
			HasSecureRPC=${HasSecureRPC} \
			HasPam=${HasPam} \
			ExtendedInputDevices=${ExtendedInputDevices}
MAKE_ENV=		MAN_INSTALL_TARGET=FreeBSDPortsInstall.man
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= 	FreeBSDPortsInstall  FreeBSDPortsInstall.man
MAN1=			SuperProbe.1 \
			XFree86.1 \
			Xserver.1 \
			kbd_mode.1 \
			pcitweak.1 \
			scanpci.1 \
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
			keyboard.4 \
			mouse.4
MAN5= 			XF86Config.5

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
.if !exists(/sys) && !exists(/usr/src/sys)
BuildXF86DRI=		NO
PLIST_SUB+=	DRI="@comment "
.else
PLIST_SUB+=	DRI=""
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

.if defined(BuildXF86DRI) && ${BuildXF86DRI} == NO
pre-fetch:
	@${ECHO_MSG} "DRI would not build: kernel source required in /sys."
.endif

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.pre.mk>
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

post-install:
	strip ${PREFIX}/bin/XFree86

.include <bsd.port.post.mk>
