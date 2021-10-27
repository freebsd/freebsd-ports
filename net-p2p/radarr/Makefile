PORTNAME=	radarr
PORTVERSION=	3.2.2.5080
DISTVERSIONPREFIX=v
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Radarr/Radarr/releases/download/v${PORTVERSION}/
DISTNAME=	Radarr.master.${PORTVERSION}.linux

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Movie Library Manager for Usenet and BitTorrent users

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl
RUN_DEPENDS=	mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3 \
		mono6.8>0:lang/mono6.8

USE_RC_SUBR=	radarr

NO_ARCH=	YES
NO_BUILD=	YES

WRKSRC=	${WRKDIR}/Radarr

USERS=	radarr
GROUPS=	radarr

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
