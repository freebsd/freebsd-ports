# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-upnp
PORTVERSION=	0.0.2a2
PORTREVISION=	26
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/177/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION:S/a/-alpha/}${DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Disk Recorder - UPnP/DLNA plugin (alpha!)

LIB_DEPENDS+=	libavcodec0.so:multimedia/ffmpeg0 \
		libboost_system.so:devel/boost-libs \
		libupnp.so:devel/upnp \
		libsqlite3.so:databases/sqlite3

USES=		tar:tgz
DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION:S/a2//}

CXXFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0 -lavcodec0 -lavformat0 -fPIC
MAKE_ARGS=	LIBS="-I${LOCALBASE}/include/ffmpeg0" CXXFLAGS="${CXXFLAGS}"

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		${WRKSRC}/Makefile

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/vdr

post-install: post-install-pluginlocales
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/icons
	@${INSTALL_DATA} ${WRKSRC}/http/icons/* \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/icons
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/xml
	@${INSTALL_DATA} ${WRKSRC}/http/xml/* \
		${STAGEDIR}${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/xml
	@${MKDIR} ${STAGEDIR}/var/cache/vdr/${PLUGIN}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
