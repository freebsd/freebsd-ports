PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
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
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:v0.5.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:ad29c8ab022f:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:6f6e22806c34:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.5:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:d08c68adba83:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:87f333178d59:google_starlark_go/vendor/go.starlark.net \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.40.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.3:h12w_socks/vendor/h12.io/socks \
		lucas-clemente:quic-go:v0.23.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-16:v0.1.4:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.0:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.4:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		pelletier:go-toml:v1.9.4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pires:go-proxyproto:v0.6.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		refraction-networking:utls:0b2885c8c0d4:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		seiflotfy:cuckoofilter:bc6005554a0c:seiflotfy_cuckoofilter/vendor/github.com/seiflotfy/cuckoofilter \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		xtls:Go:3632bf3b7499:xtls_go/vendor/github.com/xtls/go

PLIST_FILES=	bin/xray

.include <bsd.port.mk>
