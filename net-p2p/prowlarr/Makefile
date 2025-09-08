PORTNAME=	prowlarr
DISTVERSION=	2.0.5.5160
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Prowlarr/Prowlarr/releases/download/v${DISTVERSION}/
DISTNAME=	Prowlarr.master.${DISTVERSION}.freebsd-core-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Indexer Manager for Usenet and BitTorrent users
WWW=		https://github.com/Prowlarr/Prowlarr

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
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

WRKSRC=		${WRKDIR}/Prowlarr

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-extract:
	${RM} -rf ${WRKSRC}/Prowlarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Prowlarr"
	${INSTALL_PROGRAM} ${WRKSRC}/Prowlarr ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
