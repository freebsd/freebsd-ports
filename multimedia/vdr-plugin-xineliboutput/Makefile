# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20120511
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF:release \
		LOCAL:snapshot
MASTER_SITE_SUBDIR=	xineliboutput/files/xineliboutput/vdr-xineliboutput-${PORTVERSION}/:release \
		nox/:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - xineliboutput plugin/viewer

LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine \
		avutil:${PORTSDIR}/multimedia/ffmpeg \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		vdpau:${PORTSDIR}/multimedia/libvdpau

USE_BZIP2=	yes
PATCH_STRIP=	-p1
USES=		pkgconfig
USE_XORG+=	xrandr xrender
USE_GL=		gl glu glut
PORTDOCS=	COPYING README HISTORY
PORTEXAMPLES=	xine
WRKSRC=		${WRKDIR}/vdr-${PLUGIN}
XINE_PLUGINSDIR=	lib/xine/plugins/2.3

OPTIONS_DEFINE=	LIBBLURAY LIBEXTRACTOR

HAS_CONFIGURE=	yes
NO_STAGE=	yes

.include	"${.CURDIR}/../vdr/Makefile.plugins"

.include <bsd.port.pre.mk>

PLIST_SUB+=	XINE_PLUGINSDIR=${XINE_PLUGINSDIR}

CONFIGURE_ARGS+=	--cc="${CC}" --cxx="${CXX}" --add-cflags=-I${VDRDIR}

.if ${PORT_OPTIONS:MLIBEXTRACTOR}
LIB_DEPENDS+=	extractor:${PORTSDIR}/textproc/libextractor
.else
CONFIGURE_ARGS+=	--disable-libextractor
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
LIB_DEPENDS+=	bluray:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_ARGS+=	--disable-libbluray
.endif

post-patch: post-patch-plugin
# clang doesn't know -MG
	${TOUCH} -t 200001010000 ${WRKSRC}/nosignal_720x576.c \
		${WRKSRC}/black_720x576.c ${WRKSRC}/vdrlogo_720x576.c

post-install: post-install-pluginlocales
	@${INSTALL} -o ${VDR_USER} -g ${VDR_GROUP} -d ${PREFIX}/etc/vdr/plugins/${PLUGIN}
	@${INSTALL_DATA} ${WRKSRC}/examples/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf.sample
	@if [ ! -f ${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf ]; then \
	    ${INSTALL_DATA} ${WRKSRC}/examples/allowed_hosts.conf ${PREFIX}/etc/vdr/plugins/${PLUGIN}; \
	fi
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/xine
	${INSTALL_DATA} ${FILESDIR}/keymap ${EXAMPLESDIR}/xine
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
