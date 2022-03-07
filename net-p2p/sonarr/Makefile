PORTNAME=	sonarr
PORTVERSION=	3.0.7.1477
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.sonarr.tv/v3/main/${PORTVERSION}/
DISTNAME=	Sonarr.main.${PORTVERSION}.linux

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	PVR for Usenet and BitTorrent users

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3 \
		mono6.8>0:lang/mono6.8

USE_RC_SUBR=	sonarr

NO_ARCH=	YES
NO_BUILD=	YES

SUB_FILES=	${PORTNAME} package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

WRKSRC=	${WRKDIR}/Sonarr

USERS=	sonarr
GROUPS=	sonarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

.include <bsd.port.options.mk>

post-extract:
	${RM} -rf ${WRKSRC}/Sonarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Sonarr.exe"
	${INSTALL_SCRIPT} ${WRKSRC}/Sonarr.exe ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
