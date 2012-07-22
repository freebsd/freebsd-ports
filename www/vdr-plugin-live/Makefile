# New ports collection makefile for:	vdr-plugin-live
# Date created:		Wed Apr 14 18:11:42 CEST 2010
# Whom:			Juergen Lock <nox@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vdr-plugin-live
PORTVERSION=	0.2.0s20120325
PORTREVISION=	1
CATEGORIES=	www multimedia
MASTER_SITES=	http://live.vdr-developer.org/downloads/:release \
		LOCAL/nox/:snapshot
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:snapshot

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - live web plugin

LIB_DEPENDS+=	tntnet:${PORTSDIR}/www/tntnet \
		pcre:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
PATCH_STRIP=	-p1
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/vdr-plugin-${PLUGIN}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/httpd/Makefile ${WRKSRC}/pages/Makefile
MAKE_ARGS+=	INCLUDES="-I$(LOCALBASE)/include -I${WRKSRC}"

.include	"${.CURDIR}/../../multimedia/vdr/Makefile.plugins"

post-patch: post-patch-plugin
	${CP} ${FILESDIR}/gen_version_suffix.h ${WRKSRC}

post-install: post-install-pluginlocales
	(cd ${WRKSRC}/${PLUGIN} && \
		${COPYTREE_SHARE} \* ${PREFIX}/etc/vdr/plugins/${PLUGIN} )
	${CHOWN} -R ${VDR_USER}:${VDR_GROUP} ${PREFIX}/etc/vdr/plugins/${PLUGIN}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
