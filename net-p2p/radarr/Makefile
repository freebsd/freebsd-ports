# $FreeBSD$

PORTNAME=	radarr
PORTVERSION=	0.2.0.1480
DISTVERSIONPREFIX=v
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Radarr/Radarr/releases/download/v${PORTVERSION}/
DISTNAME=	Radarr.develop.${PORTVERSION}.linux

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Movie Library Manager for Usenet and BitTorrent users

LICENSE=	GPLv3

RUN_DEPENDS=	mono>0:lang/mono \
		mediainfo>0:multimedia/mediainfo \
		sqlite3>0:databases/sqlite3
LIB_DEPENDS=	libcurl.so:ftp/curl

USE_RC_SUBR=	radarr

NO_ARCH=	YES
NO_BUILD=	YES

USERS=	radarr
GROUPS=	radarr

OPTIONS_DEFINE=	X11

# Permits image resizing
X11_LIB_DEPENDS+=libgdiplus.so:x11-toolkits/libgdiplus

WRKSRC=	${WRKDIR}/Radarr

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}

post-install:
	@${FIND} -s ${STAGEDIR}${DATADIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}

.include <bsd.port.mk>
