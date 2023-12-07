PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/v2fly/geoip/releases/download/202309080643/:geoip \
		https://github.com/v2fly/domain-list-community/releases/download/20230911142809/:geosite
DISTFILES=	geoip.dat:geoip \
		dlc.dat:geosite
EXTRACT_ONLY=	v${DISTVERSION}.zip \
		xtls-Xray-core-v${DISTVERSION}_GH0.tar.gz

MAINTAINER=	kirill@drlebedev.com
COMMENT=	Set of network penetration tools
WWW=		https://github.com/XTLS/Xray-core

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_RC_SUBR=	xray
SUB_FILES=	pkg-message

USERS=		v2ray
GROUPS=		v2ray

SUB_LIST=	GROUP="${GROUPS}" \
		USER="${USERS}"

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./main:xray

USE_GITHUB=	yes
GH_ACCOUNT=	xtls
GH_PROJECT=	Xray-core

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dlc.dat ${STAGEDIR}${DATADIR}/geosite.dat
	${INSTALL_DATA} ${FILESDIR}/*.json ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
