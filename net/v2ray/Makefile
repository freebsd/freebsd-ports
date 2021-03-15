# $FreeBSD$

PORTNAME=	v2ray
DISTVERSIONPREFIX=	v
DISTVERSION=	4.35.0
CATEGORIES=	net

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Platform for building proxies to bypass network restrictions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
USE_RC_SUBR=	v2ray

GH_ACCOUNT=	v2fly
GH_PROJECT=	v2ray-core
GH_TUPLE=	\
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-metro:85c65e2d0165:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		ebfe:bcrypt_pbkdf:3c8d2dcb253a:ebfe_bcrypt_pbkdf/vendor/github.com/ebfe/bcrypt_pbkdf \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:134d130e1a04:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:e043a3d3c984:google_starlark_go/vendor/go.starlark.net \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.36.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.2:h12w_socks/vendor/h12.io/socks \
		lucas-clemente:quic-go:v0.19.3:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-15:v0.1.1:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls:v0.10.0:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		miekg:dns:v1.1.40:miekg_dns/vendor/github.com/miekg/dns \
		pires:go-proxyproto:v0.4.2:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		seiflotfy:cuckoofilter:bc6005554a0c:seiflotfy_cuckoofilter/vendor/github.com/seiflotfy/cuckoofilter \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		v2fly:VSign:e2adc24bf848:v2fly_vsign/vendor/github.com/v2fly/VSign

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
