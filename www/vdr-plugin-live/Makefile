# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-live
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	www multimedia
MASTER_SITES=	http://live.vdr-developer.org/downloads/:release \
		LOCAL/nox/:snapshot
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - live web plugin

LIB_DEPENDS+=	libtntnet.so:www/tntnet \
		libpcre.so:devel/pcre

PATCH_STRIP=	-p1
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${PORTVERSION}
VDR_PLUGIN_MAKEFILES=	${WRKSRC}/httpd/Makefile ${WRKSRC}/pages/Makefile
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include -I${WRKSRC}"
MAKE_ARGS+=	PREFIX="${PREFIX}"
USES=		compiler:c++11-lang
USE_CXXSTD=	c++11

OPTIONS_DEFINE=	DOCS

.include	"${.CURDIR}/../../multimedia/vdr/Makefile.plugins"

.include <bsd.port.pre.mk>

.if ${COMPILER_FEATURES:Mlibc++}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-libcxx
EXTRA_PATCH_STRIP=	-p1
.endif

post-patch: post-patch-plugin
	${CP} ${FILESDIR}/gen_version_suffix.h ${WRKSRC}

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	(cd ${WRKSRC}/${PLUGIN} && ${COPYTREE_SHARE} \* \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN} )
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.post.mk>
