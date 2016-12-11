# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20120511
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	SF/xineliboutput/files/xineliboutput/vdr-xineliboutput-${PORTVERSION}/:release \
		LOCAL/nox:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - xineliboutput plugin/viewer

LIB_DEPENDS+=	libxine.so:multimedia/libxine \
		libavutil.so:multimedia/ffmpeg \
		libdbus-glib-1.so:devel/dbus-glib \
		libvdpau.so:multimedia/libvdpau

PATCH_STRIP=	-p1
USES=		pkgconfig tar:bzip2
USE_XORG+=	xrandr xrender
USE_GL=		gl glu glut
PORTDOCS=	COPYING README HISTORY
PORTEXAMPLES=	xine
WRKSRC=		${WRKDIR}/vdr-${PLUGIN}
XINE_PLUGINSDIR=	lib/xine/plugins/2.5

OPTIONS_DEFINE=	LIBBLURAY LIBEXTRACTOR EXAMPLES DOCS

HAS_CONFIGURE=	yes

.include	"${.CURDIR}/../vdr/Makefile.plugins"

.include <bsd.port.pre.mk>

PLIST_SUB+=	XINE_PLUGINSDIR=${XINE_PLUGINSDIR}

CONFIGURE_ARGS+=	--cc="${CC}" --cxx="${CXX}" --add-cflags=-I${VDRDIR}

.if ${PORT_OPTIONS:MLIBEXTRACTOR}
LIB_DEPENDS+=	libextractor.so:textproc/libextractor
.else
CONFIGURE_ARGS+=	--disable-libextractor
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=	libbluray.so:multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

post-patch: post-patch-plugin
# clang doesn't know -MG
	${TOUCH} -t 200001010000 ${WRKSRC}/nosignal_720x576.c \
		${WRKSRC}/black_720x576.c ${WRKSRC}/vdrlogo_720x576.c

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}
	${INSTALL_DATA} ${WRKSRC}/examples/allowed_hosts.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf.sample
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/xine
	${INSTALL_DATA} ${FILESDIR}/keymap ${STAGEDIR}${EXAMPLESDIR}/xine
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.post.mk>
