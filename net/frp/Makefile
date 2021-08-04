PORTNAME=	frp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.37.1
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reverse proxy to expose local server behind NAT/firewall to Internet

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	fatedier
GH_TUPLE=	\
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		armon:go-socks5:e75332964ef5:armon_go_socks5/vendor/github.com/armon/go-socks5 \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-oidc:v2.2.1:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		fatedier:beego:6c6a4f5bd5eb:fatedier_beego/vendor/github.com/fatedier/beego \
		fatedier:golib:1f870741e185:fatedier_golib/vendor/github.com/fatedier/golib \
		fatedier:kcp-go:fe8645b0a904:fatedier_kcp_go/vendor/github.com/fatedier/kcp-go \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-ini:ini:v1.62.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.6.1:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5ea612d1eb83:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:89ef3d95e781:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:59db8d763f22:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:yamux:259a57b3608c:hashicorp_yamux/vendor/github.com/hashicorp/yamux \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		klauspost:cpuid:v1.2.0:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:reedsolomon:v1.9.1:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		kubernetes:apimachinery:v0.21.2:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.21.2:kubernetes_client_go/vendor/k8s.io/client-go \
		leodido:go-urn:v1.2.1:leodido_go_urn/vendor/github.com/leodido/go-urn \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		nxadm:tail:v1.4.8:nxadm_tail/vendor/github.com/nxadm/tail \
		onsi:ginkgo:v1.16.4:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		onsi:gomega:v1.13.0:onsi_gomega/vendor/github.com/onsi/gomega \
		pires:go-proxyproto:v0.5.0:pires_go_proxyproto/vendor/github.com/pires/go-proxyproto \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:1555304b9b35:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rakyll:statik:v0.1.1:rakyll_statik/vendor/github.com/rakyll/statik \
		rodaine:table:v1.0.1:rodaine_table/vendor/github.com/rodaine/table \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		square:go-jose:v2.4.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		templexxx:cpufeat:3794dfbfb047:templexxx_cpufeat/vendor/github.com/templexxx/cpufeat \
		templexxx:xor:0af8e873c554:templexxx_xor/vendor/github.com/templexxx/xor \
		tjfoc:gmsm:98aa888b79d8:tjfoc_gmsm/vendor/github.com/tjfoc/gmsm \
		xtaci:lossyconn:8df528c0c9ae:xtaci_lossyconn/vendor/github.com/xtaci/lossyconn
GO_TARGET=	./cmd/frpc ./cmd/frps

USER=		nobody
SUB_LIST=	USER=${USER}
USE_RC_SUBR=	${PORTNAME}s

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/frps.ini ${STAGEDIR}${PREFIX}/etc/frps.ini.sample

.include <bsd.port.mk>
