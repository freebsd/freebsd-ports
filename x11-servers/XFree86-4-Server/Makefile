# New ports collection makefile for:	XFree86XServer-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.0
CATEGORIES=	x11-servers
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

PREFIX?=	${X11BASE}
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc
PATCHDIR=	${PORTSDIR}/x11/XFree86-4-libraries/patches
SCRIPTS_ENV+=	PREFIX=${PREFIX} \
		X11BASE=${X11BASE} \
		WRKDIR=${WRKDIR} \
		DISTDIR=${DISTDIR} \
		ExtendedInputDevices=${ExtendedInputDevices}
ALL_TARGET=	FreeBSDPortsBuild
.if defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET= FreeBSDPortsInstall
.else
INSTALL_TARGET= FreeBSDPortsInstall  FreeBSDPortsInstall.man
MANCOMPRESSED=	yes
MAN1=		SuperProbe.1 XFree86.1 Xserver.1 \
		kbd_mode.1 xf86config.1 showrgb.1
MAN3=		XF86VidMode.3 XF86VidModeDeleteModeLine.3 \
		XF86VidModeGetAllModeLines.3 XF86VidModeGetModeLine.3 \
		XF86VidModeGetMonitor.3 XF86VidModeGetViewPort.3 \
		XF86VidModeLockModeSwitch.3 XF86VidModeModModeLine.3 \
		XF86VidModeQueryExtension.3 XF86VidModeQueryVersion.3 \
		XF86VidModeSetViewPort.3 XF86VidModeSwitchMode.3 \
		XF86VidModeSwitchToMode.3
MAN4=		apm.4 ati.4 chips.4 cirrus.4 dynapro.4 fbdev.4 \
		glint.4 i740.4 keyboard.4 mga.4 microtouch.4 mouse.4 \
		neomagic.4 nv.4 r128.4 rendition.4 s3virge.4 sis.4 \
		tdfx.4 trident.4 tseng.4 vga.4 wacom.4
MAN5= 		XF86Config.5
.endif

# User Config:
# If you want to disabe Extended input devices (such as wacom tablets),
# Set following as NO. or type make ExtendefInputDevices=NO
ExtendedInputDevices?=	YES

.include <bsd.port.mk>
