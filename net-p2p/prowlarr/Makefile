PORTNAME=	prowlarr
PORTVERSION=	0.1.8.1231
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Prowlarr/Prowlarr/releases/download/v${PORTVERSION}/
DISTNAME=	Prowlarr.develop.${PORTVERSION}.freebsd-core-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Indexer Manager for Usenet and BitTorrent users

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		icu>0:devel/icu \
		libiconv>0:converters/libiconv \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind \
		openssl>0:security/openssl \
		sqlite3>0:databases/sqlite3

USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	YES

SUB_FILES=	${PORTNAME} pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

WRKSRC=		${WRKDIR}/Prowlarr

.include <bsd.port.options.mk>

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR} "! -name Prowlarr"
	${INSTALL_PROGRAM} ${WRKSRC}/Prowlarr ${STAGEDIR}/${DATADIR}

.include <bsd.port.mk>
