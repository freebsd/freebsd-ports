PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	25.7.26
CATEGORIES=	security
MASTER_SITES=	https://github.com/v2fly/geoip/releases/download/202507050144/:geoip \
		https://github.com/v2fly/domain-list-community/releases/download/20250627153051/:geosite
DISTFILES=	geoip.dat:geoip \
		dlc.dat:geosite
EXTRACT_ONLY=	XTLS-Xray-core-v${DISTVERSION}_GH0.tar.gz

MAINTAINER=	kirill@drlebedev.com
COMMENT=	Set of network penetration tools
WWW=		https://github.com/XTLS/Xray-core

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.24,modules
USE_GITHUB=	yes
GH_ACCOUNT=	XTLS
GH_PROJECT=	Xray-core
USE_RC_SUBR=	xray

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./main:xray

SUB_FILES=	pkg-message
SUB_LIST=	GROUP="${GROUPS}" \
		USER="${USERS}"

USERS=		v2ray
GROUPS=		v2ray

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dlc.dat ${STAGEDIR}${DATADIR}/geosite.dat
	${INSTALL_DATA} ${FILESDIR}/*.json.sample ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
