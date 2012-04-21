# New ports collection makefile for:	vdr-plugin-osdteletext
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-osdteletext
PORTVERSION=	0.9.2
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/899/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

#PATCH_SITES=	http://projects.vdr-developer.org/attachments/download/901/
#PATCHFILES=	receiver-fix-2.diff
#PATCH_DIST_STRIP=	-p1

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - OSD teletext plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	${INSTALL} -o ${VDR_USER} -g ${VDR_GROUP} -d /var/cache/vdr/vtx

.include <bsd.port.mk>
