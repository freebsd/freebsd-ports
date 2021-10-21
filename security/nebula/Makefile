PORTNAME=	nebula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scalable overlay networking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	slack
USE_GITHUB=	yes
GH_ACCOUNT=	slackhq
GH_TUPLE=	\
		anmitsu:go-shlex:648efa622239:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cyberdelia:go-metrics-graphite:39f87cc3b432:cyberdelia_go_metrics_graphite/vendor/github.com/cyberdelia/go-metrics-graphite \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		flynn:noise:4bdb43be3117:flynn_noise/vendor/github.com/flynn/noise \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.7:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.0:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:f84b799fce68:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		kardianos:service:v1.1.0:kardianos_service/vendor/github.com/kardianos/service \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.25:miekg_dns/vendor/github.com/miekg/dns \
		nbrownus:go-metrics-prometheus:6e6d5173d99c:nbrownus_go_metrics_prometheus/vendor/github.com/nbrownus/go-metrics-prometheus \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.2.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:d1d2010b5bee:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cac0b30c2563:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		songgao:water:fd331bda3f4b:songgao_water/vendor/github.com/songgao/water \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		vishvananda:netlink:00009fb8606a:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/vendor/github.com/vishvananda/netns

GO_TARGET=	./cmd/nebula ./cmd/nebula-cert
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	bin/nebula \
		bin/nebula-cert \
		etc/${PORTNAME}/config.yml.example

post-patch:
	${REINPLACE_CMD} -e s,/etc/nebula,${PREFIX}/etc/${PORTNAME}, \
		-e /dev:/s/nebula1/tun1/ \
		${WRKSRC}/examples/config.yml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/config.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.example

.include <bsd.port.mk>
