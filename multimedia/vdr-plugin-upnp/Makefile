# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-upnp
PORTVERSION=	0.0.2a2
PORTREVISION=	22
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/177/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION:S/a/-alpha/}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - UPnP/DLNA plugin (alpha!)

LIB_DEPENDS+=	libavcodec0.so:${PORTSDIR}/multimedia/ffmpeg0 \
		libboost_system.so:${PORTSDIR}/devel/boost-libs \
		libupnp.so:${PORTSDIR}/devel/upnp \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION:S/a2//}

CXXFLAGS+=	-L${LOCALBASE}/lib/ffmpeg0 -lavcodec0 -lavformat0 -fPIC
MAKE_ARGS=	LIBS="-I${LOCALBASE}/include/ffmpeg0" CXXFLAGS="${CXXFLAGS}"

NO_STAGE=	yes
.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin
	@${REINPLACE_CMD} \
		-e 's,lavcodec,lavcodec0,g' \
		-e 's,lavformat,lavformat0,g' \
		${WRKSRC}/Makefile

post-install: post-install-pluginlocales
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/icons
	@${INSTALL_DATA} ${WRKSRC}/http/icons/* ${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/icons
	@${MKDIR} ${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/xml
	@${INSTALL_DATA} ${WRKSRC}/http/xml/* ${PREFIX}/etc/vdr/plugins/${PLUGIN}/http/xml
	@${INSTALL} -o ${VDR_USER} -g ${VDR_GROUP} -d /var/cache/vdr/${PLUGIN}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
