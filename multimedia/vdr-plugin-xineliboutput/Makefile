# New ports collection makefile for:	vdr-plugin-xineliboutput
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20120511
PORTREVISION=	6
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
USE_PKGCONFIG=	build
USE_XORG+=	xrandr xrender
USE_GL=		gl glu glut
PORTDOCS=	COPYING README HISTORY
PORTEXAMPLES=	xine
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/vdr-${PLUGIN}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

OPTIONS_DEFINE=	LIBBLURAY LIBEXTRACTOR

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBEXTRACTOR}
LIB_DEPENDS+=	extractor:${PORTSDIR}/textproc/libextractor
CONFIGURE_OPTS+=	--enable-libextractor
.else
CONFIGURE_OPTS+=	--disable-libextractor
.endif

.if ${PORT_OPTIONS:MLIBBLURAY}
CONFIGURE_OPTS+=	--enable-libbluray
LIB_DEPENDS+=	bluray:${PORTSDIR}/multimedia/libbluray
.else
CONFIGURE_OPTS+=	--disable-libbluray
.endif

MAKE_ARGS+=	CONFIGURE_OPTS="${CONFIGURE_OPTS}"

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
