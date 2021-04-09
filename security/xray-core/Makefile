PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2
CATEGORIES=	security

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Set of network penetration tools

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./main:xray

USE_GITHUB=	yes
GH_ACCOUNT=	xtls
GH_PROJECT=	Xray-core
GH_TUPLE=	\
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-metro:85c65e2d0165:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-yaml:yaml:a5ece683394c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.5.0:golang_mock/vendor/github.com/golang/mock \
		golang:net:e57232859fb2:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:4fbd30eecc44:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:cb27e3aa2013:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:74c10e2c17dc:google_starlark_go/vendor/go.starlark.net \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.36.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.2:h12w_socks/vendor/h12.io/socks \
		lucas-clemente:quic-go:v0.20.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-15:v0.1.4:marten_seemann_qtls_go1_15/vendor/github.com/marten-seemann/qtls-go1-15 \
		marten-seemann:qtls-go1-16:v0.1.3:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		miekg:dns:v1.1.41:miekg_dns/vendor/github.com/miekg/dns \
		pelletier:go-toml:v1.8.1:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pires:go-proxyproto:v0.5.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		refraction-networking:utls:2179f286686b:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		seiflotfy:cuckoofilter:bc6005554a0c:seiflotfy_cuckoofilter/vendor/github.com/seiflotfy/cuckoofilter \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xtls:Go:3632bf3b7499:xtls_go/vendor/github.com/xtls/go

PLIST_FILES=	bin/xray

.include <bsd.port.mk>
