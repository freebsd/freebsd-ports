PORTNAME=	sonarr
PORTVERSION=	3.0.6.1342
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.sonarr.tv/v3/main/${PORTVERSION}/
DISTNAME=	Sonarr.main.${PORTVERSION}.linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PVR for Usenet and BitTorrent users

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3 \
		mono6.8>0:lang/mono6.8

USE_RC_SUBR=	sonarr

NO_ARCH=	YES
NO_BUILD=	YES
WRKSRC=	${WRKDIR}/Sonarr

USERS=	sonarr
GROUPS=	sonarr

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
