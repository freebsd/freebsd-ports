# $FreeBSD$

PORTNAME=	v2ray
DISTVERSIONPREFIX=	v
DISTVERSION=	4.25.0
CATEGORIES=	net

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Platform for building proxies to bypass network restrictions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	v2ray

GH_ACCOUNT=	v2ray
GH_PROJECT=	v2ray-core
GH_TUPLE=	dgryski:go-metro:280f6062b5bc:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		golang:crypto:8986dd9e96cf:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.2.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:eb5bcb51f2a3:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:97732733099d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:golang_text/vendor/golang.org/x/text \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.4.0:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:979af19b165c:google_starlark_go/vendor/go.starlark.net \
		gorilla:websocket:v1.4.1:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.27.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.0:h12w_socks/vendor/h12.io/socks \
		miekg:dns:v1.1.4:miekg_dns/vendor/github.com/miekg/dns \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		refraction-networking:utls:43c36d3c1f57:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		seiflotfy:cuckoofilter:56093a4d3841:seiflotfy_cuckoofilter/vendor/github.com/seiflotfy/cuckoofilter

GO_BUILDFLAGS=	-ldflags='-s -w'
GO_TARGET=	./main:v2ray \
		./infra/control/main:v2ctl
GO_TESTFLAGS=	-p 1 -tags json -timeout 30m

USERS=		v2ray
GROUPS=		v2ray

SUB_LIST=	USER="${USERS}" \
		GROUP="${GROUPS}"

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/release/config/config.json ${STAGEDIR}${ETCDIR}/config.json.sample
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_socks_vmess.json ${STAGEDIR}${ETCDIR}/vpoint_socks_vmess.json
	${INSTALL_DATA} ${WRKSRC}/release/config/vpoint_vmess_freedom.json ${STAGEDIR}${ETCDIR}/vpoint_vmess_freedom.json
	${INSTALL_DATA} ${WRKSRC}/release/config/geoip.dat ${STAGEDIR}${DATADIR}/geoip.dat
	${INSTALL_DATA} ${WRKSRC}/release/config/geosite.dat ${STAGEDIR}${DATADIR}/geosite.dat

.include <bsd.port.mk>
