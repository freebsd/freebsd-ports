PORTNAME=	sonarr
DISTVERSION=	4.0.15.2941
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Sonarr/Sonarr/releases/download/v${DISTVERSION}/
DISTNAME=	Sonarr.main.${DISTVERSION}.freebsd-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	PVR for Usenet and BitTorrent users
WWW=		https://sonarr.tv

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libiconv>0:converters/libiconv \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind

USES=	sqlite:3 ssl:run
USE_RC_SUBR=	sonarr

CONFLICTS_INSTALL=	sonarr

NO_BUILD=	YES
SUB_FILES=	sonarr package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

WRKSRC=		${WRKDIR}/Sonarr

USERS=		sonarr
GROUPS=		sonarr

post-extract:
	${RM} -rf ${WRKSRC}/Sonarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Sonarr -and ! -name ffprobe"
	${INSTALL_PROGRAM} ${WRKSRC}/Sonarr ${STAGEDIR}/${DATADIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ffprobe ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
