PORTNAME=	lidarr
PORTVERSION=	0.7.2.1878
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/lidarr/Lidarr/releases/download/v${PORTVERSION}/
DISTNAME=	Lidarr.master.${PORTVERSION}.linux

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Music collection manager for Usenet and BitTorrent users

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	mediainfo>0:multimedia/mediainfo \
		chromaprint>0:audio/chromaprint

USES=		mono sqlite
USE_RC_SUBR=	lidarr

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Lidarr

USERS=		lidarr
GROUPS=		lidarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

post-install:
	@${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
