# New ports collection makefile for:	XFree86-Server
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.2.1
PORTREVISION=	6
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	4.2.0/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X420src-1.tgz:x \
		Wraphelp.gz:local
EXTRACT_ONLY=	X420src-1.tgz

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	anholt/patches-4.2.0/
PATCHFILES=		4.2.0-4.2.1-1-freebsd.patch.gz \
			patch-nvchips.gz

MAINTAINER=	anholt@freebsd.org

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../../x11/XFree86-4-libraries/files
.for pf in patch-text-mode.c patch-xf86Configure.c patch-xf86config.c \
	patch-mga_driver.c patch-alp_xaam.c
EXTRA_PATCHES+=		${.CURDIR}/files/${pf}
.endfor
SCRIPTS_ENV=		OSVERSION=${OSVERSION} \
			HasSecureRPC=${HasSecureRPC} \
			HasPam=${HasPam} \
			ExtendedInputDevices=${ExtendedInputDevices} \
			BuildXF86DRI=${BuildXF86DRI} \
			HasGlide3=${HasGlide3} \
			HaveMatroxHal=${HaveMatroxHal} \
			CC="${CC}" \
			CXX="${CXX}" \
			CFLAGS="${CFLAGS}"
MAN1=			XFree86.1 \
			Xserver.1 \
			kbd_mode.1 \
			pcitweak.1 \
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
			XF86VidModeSwitchToMode.3 \
			XF86VidModeValidateModeLine.3
MAN4=			mga.4 \
			tdfx.4 \
			glint.4 \
			s3virge.4 \
			r128.4 \
			rendition.4 \
			savage.4 \
			nv.4 \
			siliconmotion.4 \
			vga.4 \
			keyboard.4 \
			mouse.4
MAN5=			XF86Config.5
PKGMESSAGE=		${WRKDIR}/.pkg-message
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

.include <bsd.port.pre.mk>

# XFree86 User Config:
# ---
# Name          Default		Meaning
# ----------------------------------------------------------------------------
# HasSecureRPC	YES		build with SecureRPC (require FreeBSD-3 or later)
# HasPam	YES		support PAM (require FreeBSD-3.1 or later)
# ExtendedInputDevices	YES	support extended input devices
HasSecureRPC?=		DEFAULT
HasPam?=		DEFAULT
ExtendedInputDevices?=	DEFAULT

.if ${ARCH} == i386
BuildXF86DRI=		YES
PLIST_SUB+=		DRI=""
DISTFILES+=		freebsd-glide3headers.tar.gz:local
HasGlide3=		YES
XBUILD_DIRS+=		lib/XThrStub lib/X11 lib/GL
XINSTALL_DIRS+=		lib/GL/mesa/src/drv
post-extract::
	@(cd ${WRKSRC}/lib/GL/mesa/src/drv/tdfx/ ; \
		tar xfpz ${DISTDIR}/${DIST_SUBDIR}/freebsd-glide3headers.tar.gz)
.else
pre-fetch::
	@${ECHO_MSG} "DRI only built on i386"
BuildXF86DRI=		NO
HasGlide3=		NO
PLIST_SUB+=		DRI="@comment "
.endif # i386

# Some things are not applicable if this machine is an alpha
.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
MAN1+=		scanpci.1
.endif

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
		sis.4 \
		trident.4 \
		tseng.4 \
		vesa.4 \
		vmware.4
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

.if ${ARCH} == i386
.if !defined(WITH_MATROX_GXX_DRIVER)
HaveMatroxHal=		NO
PLIST_SUB+=		MATROX="@comment "
pre-fetch::
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "Define WITH_MATROX_GXX_DRIVER to include Matrox's extra"
	@${ECHO_MSG} "\"HALLIB\" binary driver"
	@${ECHO_MSG} "********************************************************"
.else
NO_PACKAGE=	"Matrox drivers may not be distributed"
RESTRICTED=	"Matrox drivers may not be distributed."
HaveMatroxHal=		YES
MGA_DRIVER_VERSION=	2.0
MASTER_SITES+=		ftp://ftp.matrox.com/pub/mga/archive/linux/2002/:mga
DISTFILES+=		mgadrivers-${MGA_DRIVER_VERSION}-src.tgz:mga
EXTRACT_ONLY+=		mgadrivers-${MGA_DRIVER_VERSION}-src.tgz
RESTRICTED_FILES=	mgadrivers-${MGA_DRIVER_VERSION}-src.tgz
PLIST_SUB+=		MATROX=""
post-extract::
	${MV} ${WRKDIR}/mgadrivers-${MGA_DRIVER_VERSION}-src/4.2.0/drivers/src/HALlib/* \
		${WRKSRC}/programs/Xserver/hw/xfree86/drivers/mga/HALlib/
post-install::
	${INSTALL_DATA} ${WRKDIR}/mgadrivers-${MGA_DRIVER_VERSION}-src/4.2.0/drivers/src/README_HALLIB \
		${PREFIX}/lib/X11/doc/README.mga_HALLIB
.endif	# !WITH_MATROX_GXX_DRIVER
.else
HaveMatroxHal=		NO
PLIST_SUB+=		MATROX="@comment "
.endif

post-extract::
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-build:
	@${RM} -f ${PKGMESSAGE}
	@${CAT} ${.CURDIR}/pkg-message >> ${PKGMESSAGE}

post-install::
	@${SED} -e s,/usr/X11R6,${PREFIX}, ${PKGMESSAGE}
	strip ${PREFIX}/bin/XFree86

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.post.mk>
