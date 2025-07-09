PORTNAME=	v2ray
DISTVERSIONPREFIX=	v
DISTVERSION=	5.30.0
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Platform for building proxies to bypass network restrictions
WWW=		https://www.v2fly.org/ \
		https://github.com/v2fly/v2ray-core/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:1.24,modules
CPE_VENDOR=	v2fly
CPE_PRODUCT=	v2ray-core
USE_GITHUB=	yes
GH_ACCOUNT=	v2fly
GH_PROJECT=	v2ray-core
USE_RC_SUBR=	v2ray

GO_MODULE=	github.com/v2fly/v2ray-core
GO_TARGET=	./main:v2ray
GO_TESTFLAGS=	-p 1 -tags json -timeout 30m

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

USERS=		v2ray
GROUPS=		v2ray

GO_MOD_DIST=	github # https://github.com/v2fly/v2ray-core/issues/3187

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/release/config/config.json ${STAGEDIR}${ETCDIR}/config.json.sample
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_socks_vmess.json ${STAGEDIR}${ETCDIR}/vpoint_socks_vmess.json
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_vmess_freedom.json ${STAGEDIR}${ETCDIR}/vpoint_vmess_freedom.json

.include <bsd.port.mk>
