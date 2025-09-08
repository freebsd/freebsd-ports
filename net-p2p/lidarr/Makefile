PORTNAME=	lidarr
DISTVERSION=	2.13.3.4711
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/lidarr/Lidarr/releases/download/v${PORTVERSION}/
DISTNAME=	Lidarr.master.${DISTVERSION}.freebsd-core-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Music collection manager for Usenet and BitTorrent users
WWW=		https://lidarr.audio

LICENSE=	GPLv3

# See https://github.com/radarr/radarr/issues/6668 for x86 support
ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		chromaprint>0:audio/chromaprint \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libiconv>0:converters/libiconv \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind

USES=		sqlite:3 ssl:run

USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	YES

SUB_FILES=	${PORTNAME} package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

WRKSRC=		${WRKDIR}/Lidarr

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

.include <bsd.port.options.mk>

post-extract:
	${RM} -rf ${WRKSRC}/Lidarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Lidarr"
	${INSTALL_PROGRAM} ${WRKSRC}/Lidarr ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
