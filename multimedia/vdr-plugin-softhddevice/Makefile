# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-softhddevice
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/1000/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - softhddevice plugin

LIB_DEPENDS+=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libvdpau.so:${PORTSDIR}/multimedia/libvdpau \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libasound.so:${PORTSDIR}/audio/alsa-lib

USES=		pkgconfig tar:tgz
USE_XORG+=	xv x11 xcb xinerama
USE_GL+=	gl glu
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	AGPL-3.0.txt ChangeLog README.txt
CONFIG+=	-DLOCALBASE=\\\"${LOCALBASE}\\\"
CONFIG+=	-DUSE_VDPAU
CONFIG+=	-DUSE_OSS
MAKE_ARGS+=	CONFIG="${CONFIG}"
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

OPTIONS_DEFINE=	VAAPI
VAAPI_DESC=	Enable vaapi support (experimental)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVAAPI}
LIB_DEPENDS+=	libva.so:${PORTSDIR}/multimedia/libva
CONFIG+= 	-DUSE_VAAPI
.endif

post-patch: post-patch-plugin
	@${REINPLACE_CMD} \
		-e 's,libavcodec,libavcodec0,g' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
