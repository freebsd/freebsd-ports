PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/v2ray/geoip/releases/download/202308310037/:geoip \
		https://github.com/v2ray/domain-list-community/releases/download/20230825070717/:geosite
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

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/geoip.dat ${WRKSRC}/geoip.dat
	${CP} ${DISTDIR}/${DIST_SUBDIR}/dlc.dat ${WRKSRC}/geosite.dat

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${WRKSRC}/geosite.dat ${STAGEDIR}${DATADIR}/geosite.dat
	${INSTALL_DATA} ${FILESDIR}/*.json ${STAGEDIR}${ETCDIR}/

.include <bsd.port.mk>
