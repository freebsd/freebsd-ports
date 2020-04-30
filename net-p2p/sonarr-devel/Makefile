# $FreeBSD$

PORTNAME=	sonarr
PORTVERSION=	3.0.3.780
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.sonarr.tv/v3/phantom-develop/${PORTVERSION}/
PKGNAMESUFFIX=	-devel
DISTNAME=	Sonarr.phantom-develop.${PORTVERSION}.linux

MAINTAINER=	feld@FreeBSD.org
COMMENT=	PVR for Usenet and BitTorrent users

LICENSE=	GPLv3

RUN_DEPENDS=	mono>4.6.1:lang/mono \
		mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3
LIB_DEPENDS=	libcurl.so:ftp/curl

USE_RC_SUBR=	sonarr

NO_ARCH=	YES
NO_BUILD=	YES
WRKSRC=	${WRKDIR}/Sonarr

USERS=	sonarr
GROUPS=	sonarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

CONFLICTS=	sonarr-2*

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

post-install:
	@${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
