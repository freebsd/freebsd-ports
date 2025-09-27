PORTNAME=	v2ray
DISTVERSIONPREFIX=	v
DISTVERSION=	5.39.0
CATEGORIES=	net

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Platform for building proxies to bypass network restrictions
WWW=		https://www.v2fly.org/ \
		https://github.com/v2fly/v2ray-core/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	v2fly
CPE_PRODUCT=	v2ray-core
USE_GITHUB=	yes
GH_ACCOUNT=	v2fly
GH_PROJECT=	v2ray-core
USE_RC_SUBR=	v2ray

GO_MOD_DIST=	github # https://github.com/v2fly/v2ray-core/issues/3187
GO_MODULE=	github.com/v2fly/v2ray-core
GO_TARGET=	./main:v2ray
GO_TESTFLAGS=	-p 1 -tags json -timeout 30m

SUB_LIST=	GROUP="${GROUPS}" \
		USER="${USERS}"

USERS=		v2ray
GROUPS=		v2ray

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	cd ${WRKSRC}/release/config/ && \
		${INSTALL_DATA} vpoint*.json ${STAGEDIR}${ETCDIR} && \
		${INSTALL_DATA}  config.json ${STAGEDIR}${ETCDIR}/config.json.sample

.include <bsd.port.mk>
