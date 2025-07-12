PORTNAME=	radarr
DISTVERSION=	5.26.2.10099
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/Radarr/Radarr/releases/download/v${DISTVERSION}/
DISTNAME=	Radarr.master.${DISTVERSION}.freebsd-core-x64

MAINTAINER=	michiel@vanbaak.eu
COMMENT=	Movie Library Manager for Usenet and BitTorrent users
WWW=		https://radarr.video

LICENSE=	GPLv3

# See https://github.com/Radarr/Radarr/issues/6668 for x86 support
ONLY_FOR_ARCHS=	amd64

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss \
		icu>0:devel/icu \
		krb5>0:security/krb5 \
		libiconv>0:converters/libiconv \
		libinotify>0:devel/libinotify \
		libunwind>0:devel/libunwind

USES=	sqlite:3 ssl:run

USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	YES

SUB_FILES=	${PORTNAME} package_info pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		GROUPS=${GROUPS} \
		MAINTAINER=${MAINTAINER} \
		PKGVERSION=${PKGVERSION} \
		PORTNAME=${PORTNAME} \
		USERS=${USERS}

WRKSRC=		${WRKDIR}/Radarr

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

.include <bsd.port.options.mk>

post-extract:
	${RM} -rf ${WRKSRC}/Radarr.Update

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}/${DATADIR}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}/${DATADIR}/bin/ "! -name Radarr -and ! -name ffprobe"
	${INSTALL_PROGRAM} ${WRKSRC}/Radarr ${STAGEDIR}/${DATADIR}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/ffprobe ${STAGEDIR}/${DATADIR}/bin/

post-install:
	${INSTALL_DATA} ${WRKDIR}/package_info ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
