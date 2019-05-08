# $FreeBSD$

PORTNAME=	v2ray
PORTVERSION=	4.14.0
CATEGORIES=	net
MASTER_SITES=	https://github.com/v2ray/v2ray-core/releases/download/v${PORTVERSION}/
DISTNAME=	src_all
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Platform for building proxies to bypass network restrictions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/v2ray.com/core/LICENSE

USES=		go zip

NO_WRKSUBDIR=	yes
WRKSRC=		${WRKDIR}/src
GO_BUILDFLAGS+=	--ldflags '-s -w'

USE_RC_SUBR=	v2ray
USERS=		v2ray
GROUPS=		v2ray

PLIST_FILES=	bin/v2ray \
		bin/v2ctl \
		"@sample ${ETCDIR}/config.json.sample" \
		${ETCDIR}/vpoint_socks_vmess.json \
		${ETCDIR}/vpoint_vmess_freedom.json \
		${DATADIR}/geoip.dat \
		${DATADIR}/geosite.dat

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

do-build:
	@cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} -o ${GO_WRKDIR_BIN}/v2ray v2ray.com/core/main && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} -o ${GO_WRKDIR_BIN}/v2ctl v2ray.com/ext/tools/control/main

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2ray ${STAGEDIR}${PREFIX}/bin/v2ray
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2ctl ${STAGEDIR}${PREFIX}/bin/v2ctl
	${INSTALL_DATA} ${WRKSRC}/v2ray.com/core/release/config/config.json ${STAGEDIR}${ETCDIR}/config.json.sample
	${INSTALL_DATA} ${WRKSRC}/v2ray.com/core/release/config/vpoint_socks_vmess.json ${STAGEDIR}${ETCDIR}/vpoint_socks_vmess.json
	${INSTALL_DATA} ${WRKSRC}/v2ray.com/core/release/config/vpoint_vmess_freedom.json ${STAGEDIR}${ETCDIR}/vpoint_vmess_freedom.json
	${INSTALL_DATA} ${WRKSRC}/v2ray.com/core/release/config/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${WRKSRC}/v2ray.com/core/release/config/geosite.dat ${STAGEDIR}${DATADIR}/geosite.dat

.include <bsd.port.mk>
