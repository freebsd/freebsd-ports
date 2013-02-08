# Created by: Juergen Lock <nox@freebsd.org>
# $FreeBSD$

PORTNAME=	vdr-plugin-upnp
PORTVERSION=	0.0.2a2
PORTREVISION=	19
CATEGORIES=	multimedia
MASTER_SITES=	http://projects.vdr-developer.org/attachments/download/177/
DISTNAME=	${PORTNAME:S/-plugin-/-/}-${DISTVERSIONPREFIX}${DISTVERSION:S/a/-alpha/}${DISTVERSIONSUFFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video Disk Recorder - UPnP/DLNA plugin (alpha!)

LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg \
		boost_system:${PORTSDIR}/devel/boost-libs \
		upnp:${PORTSDIR}/devel/upnp \
		sqlite3:${PORTSDIR}/databases/sqlite3

DIST_SUBDIR=	vdr
PATCH_STRIP=	-p1
HAVE_CONFIGURE=	yes
PORTDOCS=	COPYING README HISTORY
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/${PLUGIN}-${DISTVERSION:S/a2//}

.include	"${.CURDIR}/../vdr/Makefile.plugins"

post-patch: post-patch-plugin

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
