# New ports collection makefile for:    XFree86-Server
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	4.3.99.15
PORTREVISION=	2
CATEGORIES=	x11-servers
MASTER_SITES=	${MASTER_SITE_XFREE:S|source/||:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	develsnaps/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-${PORTVERSION}${EXTRACT_SUFX}:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	XFree86-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 X server and related programs

CONFLICTS=	xorg-server-*
IGNORE=		Obsolete now that XFree86-4-Server has been updated to 4.4.0

# Override default from XFree86-4-libraries/Makefile.inc
PATCHDIR=		${MASTERDIR}/files

.for pf in patch-Imake.cf patch-Imake.rules \
			patch-Imake.tmpl patch-X11.tmpl patch-Xcursor-Imakefile \
			patch-c2 patch-dri-Imakefile \
			patch-f patch-imake.c \
			patch-texteroids patch-xditview-Imakefile patch-xdm \
			patch-xdm_session.c patch-xf86.tmpl \
			patch-xterm-Imakefile patch-z05 patch-z14 \
			patch-z15 patch-z30 patch-z32 patch-z34 patch-z35 \
			patch-z41 patch-z44 patch-z45
# patch-startx

EXTRA_PATCHES+=		${.CURDIR}/../../x11/XFree86-4-libraries/files/${pf}
.endfor

NO_LATEST_LINK=		yes
USE_BZIP2=		yes
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
MAN5=			XF86Config.5
PKGMESSAGE=		${WRKDIR}/.pkg-message
XBUILD_DIRS=		lib/font lib/lbxutil lib/Xdmcp lib/Xau programs/Xserver
XINCLUDE_DIRS=		lib/xkbfile lib/xtrans
XINSTALL_DIRS=		lib/font programs/Xserver
XINSTALL_MAN_DIRS=	programs/Xserver

NOT_FOR_ARCHS=		ia64

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
BROKEN=			"Does not build on amd64"
.endif

.if ${ARCH} == i386 || ${ARCH} == alpha
RUN_DEPENDS+=		${X11BASE}/lib/modules/dri/r200_dri.so:${PORTSDIR}/graphics/dri
BuildXF86DRI=		YES
PLIST_SUB+=		DRI=""
.else
BuildXF86DRI=		NO
PLIST_SUB+=		DRI="@comment "
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

.if ${ARCH} == sparc64
PLIST_SUB+=	SPARC64_NA="@comment "
PLIST_SUB+=	SPARC64=""
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
		sis.4 \
		trident.4 \
		tseng.4 \
		vesa.4 \
		via.4 \
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
