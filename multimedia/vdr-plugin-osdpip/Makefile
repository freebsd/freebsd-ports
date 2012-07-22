# New ports collection makefile for:	vdr-plugin-osdpip
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-osdpip
PORTVERSION=	0.1.1
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/880/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://projects.vdr-developer.org/attachments/download/893/
PATCHFILES=	osdpip-vdr-1.7.26.diff

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - picture-in-picture plugin

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg

DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
PATCH_DIST_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
