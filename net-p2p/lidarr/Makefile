PORTNAME=	lidarr
PORTVERSION=	0.8.1.2135
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/lidarr/Lidarr/releases/download/v${PORTVERSION}/
DISTNAME=	Lidarr.master.${PORTVERSION}.linux

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Music collection manager for Usenet and BitTorrent users

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	chromaprint>0:audio/chromaprint \
		mediainfo>0:multimedia/mediainfo \
		mono6.8>0:lang/mono6.8 \
		sqlite3>0:databases/sqlite3

USE_RC_SUBR=	lidarr

NO_ARCH=	YES
NO_BUILD=	YES

WRKSRC=	${WRKDIR}/Lidarr

SUB_FILES=	${PORTNAME} package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

USERS=	lidarr
GROUPS=	lidarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

.include <bsd.port.options.mk>

post-extract:
	${RM} -rf ${WRKSRC}/Lidarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Lidarr.exe"
	${INSTALL_SCRIPT} ${WRKSRC}/Lidarr.exe ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
