# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-osdteletext
PORTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/899/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - OSD teletext plugin

PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION}

NO_STAGE=	yes
.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

post-install: post-install-pluginlocales
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	${INSTALL} -o ${VDR_USER} -g ${VDR_GROUP} -d /var/cache/vdr/vtx

.include <bsd.port.mk>
