# New ports collection makefile for:    XFree86-Server
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.3.0
PORTREVISION=	8
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	X430src-1.tgz \
		X430src-2.tgz \
		X430src-3.tgz

MAINTAINER=	anholt@freebsd.org
COMMENT=	XFree86-4 X server and related programs

.for pf in patch-savage-pci-id patch-alpha_video.c patch-Pci.h patch-radeondri \
	patch-r128_driver.c patch-mga_driver.c patch-xkbInit.c patch-radeon_dri.c \
	patch-mga_dri.c patch-nv_driver.c patch-nv_setup.c patch-int10-generic.c \
	patch-radeon_cursor.c patch-radeon_reg.h patch-smi \
	patch-libc_wrapper.c patch-xf86-common-Imakefile patch-loader-Imakefile \
	patch-loader-elfloader.c patch-bsd-Imakefile patch-bsd-bsdResource.c \
	patch-bus-Imakefile patch-r200_vtxtmp_x86.S patch-radeon_vtxtmp_x86.S
EXTRA_PATCHES+=		${FILESDIR}/${pf}
.endfor
SCRIPTS_ENV=		OSVERSION=${OSVERSION} \
			BuildXF86DRI=${BuildXF86DRI} \
			WITH_DEBUG="${WITH_DEBUG}"
MAN1=			XFree86.1 \
			Xserver.1 \
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
MAN4=			citron.4 \
			dynapro.4 \
			elographics.4 \
			fbdevhw.4 \
			glint.4 \
			kbd.4 \
			keyboard.4 \
			mga.4 \
			microtouch.4 \
			mouse.4 \
			mutouch.4 \
			nv.4 \
			r128.4 \
			radeon.4 \
			rendition.4 \
			s3virge.4 \
			savage.4 \
			siliconmotion.4 \
			tdfx.4 \
			vga.4 \
			void.4 \
			wacom.4
MAN5=			XF86Config.5
PKGMESSAGE=		${WRKDIR}/.pkg-message
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${ARCH} == i386 ||  ${ARCH} == alpha
BuildXF86DRI=		YES
PLIST_SUB+=		DRI=""
XBUILD_DIRS+=		lib/XThrStub lib/X11 lib/Xext lib/GL
XINSTALL_DIRS+=		lib/GL/mesa/src/drv
.else
BuildXF86DRI=		NO
PLIST_SUB+=		DRI="@comment "
.endif # i386

.if ${ARCH} == alpha
PLIST_SUB+=	ALPHA_NA="@comment "
.else
PLIST_SUB+=	ALPHA_NA=""
MAN1+=		scanpci.1
.endif

.if ${ARCH} == ia64
PLIST_SUB+=	IA64_NA="@comment "
.else
PLIST_SUB+=	IA64_NA=""
.endif

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64_NA="@comment "
.else
PLIST_SUB+=	SPARC64_NA=""
.endif

.if ${ARCH} == i386
PLIST_SUB+=	I386=""
MAN4+=		apm.4 \
		chips.4 \
		cirrus.4 \
		cyrix.4 \
		i128.4 \
		i740.4 \
		i810.4 \
		neomagic.4 \
		nsc.4 \
		sis.4 \
		trident.4 \
		tseng.4 \
		vesa.4 \
		vmware.4
.else
PLIST_SUB+=	I386="@comment "
.endif

post-extract::
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-build:
	@${RM} -f ${PKGMESSAGE}
	@${CAT} ${.CURDIR}/pkg-message >> ${PKGMESSAGE}

post-install::
	@${SED} -e s,/usr/X11R6,${PREFIX}, ${PKGMESSAGE}
	@if [ -f ${PREFIX}/bin/Xwrapper-4 ] ; then \
	${LN} -sf Xwrapper-4 ${PREFIX}/bin/X; \
	fi;

.include <bsd.port.post.mk>
