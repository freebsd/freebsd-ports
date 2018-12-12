# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-softhddevice
PORTVERSION=	0.5.1
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/1000/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - softhddevice plugin

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/AGPL-3.0.txt

LIB_DEPENDS=	libavcodec0.so:multimedia/ffmpeg0 \
		libvdpau.so:multimedia/libvdpau \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libasound.so:audio/alsa-lib

USES=		compiler:features pkgconfig tar:tgz
USE_XORG=	xv x11 xcb xinerama
USE_GL=		gl glu
PATCH_STRIP=	-p1
CONFIG+=	-DLOCALBASE=\\\"${LOCALBASE}\\\"
CONFIG+=	-DUSE_VDPAU
CONFIG+=	-DUSE_OSS
MAKE_ARGS=	CONFIG="${CONFIG}"
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}

PORTDOCS=	ChangeLog README.txt

OPTIONS_DEFINE=	VAAPI DOCS NLS
VAAPI_DESC=	Enable vaapi support (experimental)

VAAPI_LIB_DEPENDS=	libva.so:multimedia/libva
VAAPI_VARS=		CONFIG+=-DUSE_VAAPI

.include	"${.CURDIR}/../vdr/Makefile.plugins"

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} != clang
USE_GCC=	yes
.endif

post-patch: post-patch-plugin
	@${REINPLACE_CMD} \
		-e 's,libavcodec,libavcodec0,g' \
		${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/iatomic.h ${WRKSRC}
	@${REINPLACE_CMD} \
		-e 's,<alsa/iatomic.h>,"iatomic.h",' \
		${WRKSRC}/*.c ${WRKSRC}/*.cpp

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
