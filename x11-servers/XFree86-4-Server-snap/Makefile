# New ports collection makefile for:	XFree86XServer-4.0.1
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.0.1
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X401src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${PORTSDIR}/x11/XFree86-4-libraries/patches
SCRIPTS_ENV+=		PREFIX=${PREFIX} \
			X11BASE=${X11BASE} \
			WRKDIR=${WRKDIR} \
			DISTDIR=${DISTDIR} \
			ExtendedInputDevices=${ExtendedInputDevices}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET= 	FreeBSDPortsInstall  FreeBSDPortsInstall.man
MANCOMPRESSED=		yes
MAN1=			SuperProbe.1 \
			XFree86.1 \
			Xserver.1 \
			imake.1 \
			kbd_mode.1 \
			lndir.1 \
			makedepend.1 \
			makeg.1 \
			makestrs.1 \
			mkdirhier.1 \
			pswrap.1 \
			revpath.1 \
			rman.1 \
			showrgb.1 \
			xf86config.1 \
			xmkmf.1
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
MAN4=			apm.4 \
			ati.4 \
			chips.4 \
			cirrus.4 \
			cyrix.4 \
			dynapro.4 \
			elographics.4 \
			fbdev.4 \
			glint.4 \
			i740.4 \
			i810.4 \
			keyboard.4 \
			mga.4 \
			microtouch.4 \
			mouse.4 \
			mutouch.4 \
			neomagic.4 \
			nv.4 \
			r128.4 \
			rendition.4 \
			s3virge.4 \
			sis.4 \
			tdfx.4 \
			trident.4 \
			tseng.4 \
			vga.4 \
			wacom.4
MAN5= 			XF86Config.5

# User Config:
# If you want to disabe Extended input devices (such as wacom tablets),
# Set following as NO. or type make ExtendefInputDevices=NO
ExtendedInputDevices?=	YES

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-everything:
	${SH} ${PKGDIR}/INSTALL
.endif

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.mk>
