PORTNAME=	xray-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.5
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Set of network penetration tools

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.18,modules

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	./main:xray

USE_GITHUB=	yes
GH_ACCOUNT=	xtls
GH_PROJECT=	Xray-core

GH_TUPLE=	\
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-metro:adc40b04c140:dgryski_go_metro/vendor/github.com/dgryski/go-metro \
		francoispqt:gojay:v1.2.13:francoispqt_gojay/vendor/github.com/francoispqt/gojay \
		fsnotify:fsnotify:v1.5.3:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-task:slim-sprig:348f09dbbbc0:go_task_slim_sprig/vendor/github.com/go-task/slim-sprig \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:7b82a4e95df4:golang_crypto/vendor/golang.org/x/crypto \
		golang:mock:v1.6.0:golang_mock/vendor/github.com/golang/mock \
		golang:mod:9b9b3d81d5e3:golang_mod/vendor/golang.org/x/mod \
		golang:net:1d1ef9303861:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:9388b58f7150:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.10:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:2f41105eb62f:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.7:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:b37d22cd5731:google_go_genproto/vendor/google.golang.org/genproto \
		google:starlark-go:d1966c6b9fcd:google_starlark_go/vendor/go.starlark.net \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.46.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h12w:socks:v1.0.3:h12w_socks/vendor/h12.io/socks \
		lucas-clemente:quic-go:v0.27.0:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:qtls-go1-16:v0.1.5:marten_seemann_qtls_go1_16/vendor/github.com/marten-seemann/qtls-go1-16 \
		marten-seemann:qtls-go1-17:v0.1.1:marten_seemann_qtls_go1_17/vendor/github.com/marten-seemann/qtls-go1-17 \
		marten-seemann:qtls-go1-18:v0.1.1:marten_seemann_qtls_go1_18/vendor/github.com/marten-seemann/qtls-go1-18 \
		miekg:dns:v1.1.48:miekg_dns/vendor/github.com/miekg/dns \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.5:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		pelletier:go-toml:v1.9.5:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pires:go-proxyproto:v0.6.2:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.28.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		refraction-networking:utls:v1.0.0:refraction_networking_utls/vendor/github.com/refraction-networking/utls \
		riobard:go-bloom:cdc8013cb5b3:riobard_go_bloom/vendor/github.com/riobard/go-bloom \
		seiflotfy:cuckoofilter:e3b120b3f5fb:seiflotfy_cuckoofilter/vendor/github.com/seiflotfy/cuckoofilter \
		stretchr:objx:v0.1.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify \
		v2fly:ss-bloomring:28617310f63e:v2fly_ss_bloomring/vendor/github.com/v2fly/ss-bloomring \
		xtls:Go:d4af136d3672:xtls_go/vendor/github.com/xtls/go

PLIST_FILES=	bin/xray

.include <bsd.port.mk>
