PORTNAME=	vdr-plugin-osdpip
PORTVERSION=	0.1.2
PORTREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/961/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DIST_SUBDIR=	vdr

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - picture-in-picture plugin
WWW=		https://projects.vdr-developer.org/projects/plg-osdpip

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to build with FFmpeg 6
DEPRECATED=	Depends on abandoned fork of VDR
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg

USES=		pkgconfig tar:tgz
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
