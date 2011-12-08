# New ports collection makefile for:	vdr-plugin-xineliboutput
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-xineliboutput
PORTVERSION=	1.0.90s20110308.2305
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	SF:release \
		LOCAL:snapshot
MASTER_SITE_SUBDIR=	xineliboutput/files/xineliboutput/vdr-xineliboutput-${PORTVERSION}/:release \
		nox/:snapshot
DISTNAME=	${PORTNAME:S/-plugin-/-plugin-/}_${DISTVERSIONPREFIX}${DISTVERSION:S/s/+cvs/:S/$/.orig/}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - xineliboutput plugin/viewer

LIB_DEPENDS+=	extractor.3:${PORTSDIR}/textproc/libextractor \
		xine.1:${PORTSDIR}/multimedia/libxine \
		avutil.1:${PORTSDIR}/multimedia/ffmpeg \
		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		vdpau.1:${PORTSDIR}/multimedia/libvdpau

PATCH_STRIP=	-p1
USE_GNOME+=	pkgconfig
USE_XORG+=	xrandr xrender
USE_GL=		gl glu glut
PORTDOCS=	COPYING README
PORTEXAMPLES=	xine
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/vdr-${PLUGIN}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

MAKE_ARGS+=	CONFIGURE_OPTS="${CONFIGURE_OPTS}"

.include <bsd.port.pre.mk>

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
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/xine
	${INSTALL_DATA} ${FILESDIR}/keymap ${EXAMPLESDIR}/xine
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
