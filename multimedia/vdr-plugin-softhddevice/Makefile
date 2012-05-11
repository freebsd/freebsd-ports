# New ports collection makefile for:	vdr-plugin-softhddevie
# Date created:		Sun Apr 29 17:00:02 CEST 2012
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-softhddevice
PORTVERSION=	0.5.0
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/919/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - softhddevice plugin

LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg \
		vdpau.1:${PORTSDIR}/multimedia/libvdpau \
		xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-keysyms.1:${PORTSDIR}/x11/xcb-util-keysyms \
		asound.2:${PORTSDIR}/audio/alsa-lib

USE_GNOME+=	pkgconfig
USE_XORG+=	xv x11 xinerama
USE_GL+=	gl glu
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	AGPL-3.0.txt ChangeLog README.txt
CONFIG+=	-DLOCALBASE=\\\"${LOCALBASE}\\\"
CONFIG+=	-DUSE_VDPAU
CONFIG+=	-DUSE_OSS
MAKE_ARGS+=	CONFIG="${CONFIG}"
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

OPTIONS=	VAAPI	"Enable vaapi support (experimental)"		off

.include <bsd.port.options.mk>

.if defined(WITH_VAAPI)
LIB_DEPENDS+=	va.1:${PORTSDIR}/multimedia/libva
CONFIG+= 	-DUSE_VAAPI
.endif

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
