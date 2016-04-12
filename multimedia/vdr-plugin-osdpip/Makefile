# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-osdpip
PORTVERSION=	0.1.1
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/880/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

PATCH_SITES=	http://projects.vdr-developer.org/attachments/download/893/
PATCHFILES=	osdpip-vdr-1.7.26.diff

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - picture-in-picture plugin

LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg

USES=		pkgconfig tar:tgz
DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
PATCH_DIST_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
