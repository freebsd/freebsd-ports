# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-skinenigmang
PORTVERSION=	0.1.2s20120606
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://andreas.vdr-developer.org/enigmang/download/:release \
		LOCAL/nox:snapshot
DISTNAME=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME}.tar.bz2:snapshot \
		skinenigmang-logos-xpm-hi-20070702.tgz:release

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - Enigma-NG skin plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
	(cd ${WRKDIR}/${PLUGIN} && \
		${COPYTREE_SHARE} \* ${PREFIX}/etc/vdr/plugins/${PLUGIN} )
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
