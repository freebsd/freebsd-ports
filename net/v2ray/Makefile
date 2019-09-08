# $FreeBSD$

PORTNAME=	v2ray
DISTVERSIONPREFIX=	v
DISTVERSION=	4.20.0
CATEGORIES=	net

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Platform for building proxies to bypass network restrictions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build

USES=		go
USE_GITHUB=	yes
USE_RC_SUBR=	v2ray

GH_ACCOUNT=	v2ray
GH_PROJECT=	v2ray-core
GH_SUBDIR=	src/v2ray.com/core
GH_TUPLE=	golang:crypto:193df9c0f06f:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.2.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:65e2d4e15006:golang_net/vendor/golang.org/x/net \
		golang:protobuf:c823c79ea157:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:1d60e4601c6f:golang_sync/vendor/golang.org/x/sync \
		golang:sys:49385e6e1522:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		google:go-cmp:v0.2.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:11092d34479b:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:1174b2613e82:google_starlark_go/vendor/go.starlark.net \
		grpc:grpc-go:v1.18.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.0:h12w_socks/vendor/h12.io/socks \
		miekg:dns:v1.1.4:miekg_dns/vendor/github.com/miekg/dns

GO_BUILDFLAGS=	--ldflags '-s -w'

USERS=		v2ray
GROUPS=		v2ray

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

do-build:
	@cd ${GO_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} -o ${GO_WRKDIR_BIN}/v2ray v2ray.com/core/main && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build ${GO_BUILDFLAGS} -o ${GO_WRKDIR_BIN}/v2ctl v2ray.com/core/infra/control/main

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2ray ${STAGEDIR}${PREFIX}/bin/v2ray
	${INSTALL_PROGRAM} ${WRKDIR}/bin/v2ctl ${STAGEDIR}${PREFIX}/bin/v2ctl
	${INSTALL_DATA} ${WRKSRC}/release/config/config.json ${STAGEDIR}${ETCDIR}/config.json.sample
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_socks_vmess.json ${STAGEDIR}${ETCDIR}/vpoint_socks_vmess.json
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_vmess_freedom.json ${STAGEDIR}${ETCDIR}/vpoint_vmess_freedom.json
	${INSTALL_DATA} ${WRKSRC}/release/config/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${WRKSRC}/release/config/geosite.dat ${STAGEDIR}${DATADIR}/geosite.dat

do-test:
	@cd ${GO_WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} test -p 1 -tags json -v -timeout 30m ./...

.include <bsd.port.mk>
