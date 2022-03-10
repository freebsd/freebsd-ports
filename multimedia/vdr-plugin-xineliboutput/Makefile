# Created by: Juergen Lock <nox@FreeBSD.org>

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20120511
PORTREVISION=	32
CATEGORIES=	multimedia
MASTER_SITES=	SF/xineliboutput/files/xineliboutput/vdr-xineliboutput-${PORTVERSION}/:release \
		LOCAL/nox:snapshot
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - xineliboutput plugin/viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg \
		libdbus-glib-1.so:devel/dbus-glib \
		libvdpau.so:multimedia/libvdpau \
		libxine.so:multimedia/libxine

USES=		compiler:c++11-lang gl pkgconfig tar:bzip2 xorg
USE_GL=		gl glu glut
USE_XORG=	xrandr xrender

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--add-cflags=-I${VDRDIR} \
		--cc="${CC}" \
		--cxx="${CXX}"

PATCH_STRIP=	-p1

WRKSRC=			${WRKDIR}/vdr-${PLUGIN}
XINE_PLUGINSDIR=	lib/xine/plugins/2.10

PLIST_SUB=	XINE_PLUGINSDIR=${XINE_PLUGINSDIR}
PORTDOCS=	HISTORY README
PORTEXAMPLES=	xine

OPTIONS_DEFINE=	DOCS EXAMPLES LIBBLURAY LIBEXTRACTOR NLS
OPTIONS_SUB=	yes

LIBBLURAY_LIB_DEPENDS=		libbluray.so:multimedia/libbluray
LIBBLURAY_CONFIGURE_ENABLE=	libbluray
LIBEXTRACTOR_LIB_DEPENDS=	libextractor.so:textproc/libextractor
LIBEXTRACTOR_CONFIGURE_ENABLE=	libextractor

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

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/xine
	${INSTALL_DATA} ${FILESDIR}/keymap ${STAGEDIR}${EXAMPLESDIR}/xine

.include <bsd.port.mk>
