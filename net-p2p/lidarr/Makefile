# $FreeBSD$

PORTNAME=	lidarr
PORTVERSION=	0.6.2.883
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/lidarr/Lidarr/releases/download/v${PORTVERSION}/
DISTNAME=	Lidarr.develop.${PORTVERSION}.linux

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Music collection manager for Usenet and BitTorrent users

LICENSE=	GPLv3

RUN_DEPENDS=	mono>0:lang/mono \
		mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3 \
		chromaprint>0:audio/chromaprint
LIB_DEPENDS=	libcurl.so:ftp/curl

USE_RC_SUBR=	lidarr

NO_ARCH=	YES
NO_BUILD=	YES
WRKSRC=	${WRKDIR}/Lidarr

USERS=	lidarr
GROUPS=	lidarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

post-install:
	@${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
