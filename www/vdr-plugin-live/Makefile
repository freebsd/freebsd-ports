# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-live
PORTVERSION=	0.2.0s20120325
PORTREVISION=	2
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
WRKSRC=		${WRKDIR}/vdr-plugin-${PLUGIN}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/httpd/Makefile ${WRKSRC}/pages/Makefile
MAKE_ARGS+=	INCLUDES="-I$(LOCALBASE)/include -I${WRKSRC}"
MAKE_ARGS+=	PREFIX="${PREFIX}"
USES=		compiler:features

NO_STAGE=	yes

.include	"${.CURDIR}/../../multimedia/vdr/Makefile.plugins"

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-libcxx
EXTRA_PATCH_STRIP=	-p1
.endif

post-patch: post-patch-plugin
	${CP} ${FILESDIR}/gen_version_suffix.h ${WRKSRC}

pre-su-install:
	${MKDIR} ${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	(cd ${WRKSRC}/${PLUGIN} && \
		${COPYTREE_SHARE} \* ${PREFIX}/etc/vdr/plugins/${PLUGIN} )
	${CHOWN} -R ${VDR_USER}:${VDR_GROUP} ${PREFIX}/etc/vdr/plugins/${PLUGIN}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
