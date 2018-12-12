# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20120511
PORTREVISION=	25
CATEGORIES=	multimedia
MASTER_SITES=	SF/xineliboutput/files/xineliboutput/vdr-xineliboutput-${PORTVERSION}/:release \
		LOCAL/nox:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - xineliboutput plugin/viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxine.so:multimedia/libxine \
		libavutil.so:multimedia/ffmpeg \
		libdbus-glib-1.so:devel/dbus-glib \
		libvdpau.so:multimedia/libvdpau

PATCH_STRIP=	-p1
USES=		compiler:c++11-lang pkgconfig tar:bzip2
USE_XORG=	xrandr xrender
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --cxx="${CXX}" --add-cflags=-I${VDRDIR}
USE_GL=		gl glu glut
WRKSRC=		${WRKDIR}/vdr-${PLUGIN}
XINE_PLUGINSDIR=lib/xine/plugins/2.7

PORTDOCS=	README HISTORY
PORTEXAMPLES=	xine

PLIST_SUB=	XINE_PLUGINSDIR=${XINE_PLUGINSDIR}

OPTIONS_DEFINE=	LIBBLURAY LIBEXTRACTOR EXAMPLES DOCS

LIBEXTRACTOR_LIB_DEPENDS=	libextractor.so:textproc/libextractor
LIBEXTRACTOR_CONFIGURE_ENABLE=	libextractor
LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
# clang doesn't know -MG
	${TOUCH} -t 200001010000 ${WRKSRC}/nosignal_720x576.c \
		${WRKSRC}/black_720x576.c ${WRKSRC}/vdrlogo_720x576.c

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}
	${INSTALL_DATA} ${WRKSRC}/examples/allowed_hosts.conf \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/allowed_hosts.conf.sample

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/xine
	${INSTALL_DATA} ${FILESDIR}/keymap ${STAGEDIR}${EXAMPLESDIR}/xine

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
