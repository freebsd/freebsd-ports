PORTNAME=	nebula
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	security
MASTER_SITES=	https://git.zx2c4.com/wintun-go/snapshot/:wintungo
DISTFILES=	wintun-go-${GO_WINTUN_REV}.tar.xz:wintungo

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Scalable overlay networking tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe go:modules
CPE_VENDOR=	slack
USE_GITHUB=	yes
GH_ACCOUNT=	slackhq
GH_TUPLE=	\
		anmitsu:go-shlex:38f4b401e2be:anmitsu_go_shlex/vendor/github.com/anmitsu/go-shlex \
		armon:go-radix:v1.0.0:armon_go_radix/vendor/github.com/armon/go-radix \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cyberdelia:go-metrics-graphite:39f87cc3b432:cyberdelia_go_metrics_graphite/vendor/github.com/cyberdelia/go-metrics-graphite \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		flynn:noise:v1.0.0:flynn_noise/vendor/github.com/flynn/noise \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:crypto:089bfa567519:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:4a448f8816b3:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:7861aae1554b:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		imdario:mergo:v0.3.8:imdario_mergo/vendor/github.com/imdario/mergo \
		kardianos:service:v1.2.0:kardianos_service/vendor/github.com/kardianos/service \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		nbrownus:go-metrics-prometheus:974a6260965f:nbrownus_go_metrics_prometheus/vendor/github.com/nbrownus/go-metrics-prometheus \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:cf1acfcdf475:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		songgao:water:2b4b6d7c09d8:songgao_water/vendor/github.com/songgao/water \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		vishvananda:netlink:v1.1.0:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:50045581ed74:vishvananda_netns/vendor/github.com/vishvananda/netns

GO_WINTUN_REV=	415007cec224
GO_TARGET=	./cmd/nebula ./cmd/nebula-cert
USE_RC_SUBR=	${PORTNAME}
PLIST_FILES=	bin/nebula \
		bin/nebula-cert \
		etc/${PORTNAME}/config.yml.example

post-extract:
	${MKDIR} ${WRKSRC}/vendor/golang.zx2c4.com
	${MV} ${WRKDIR}/wintun-go-${GO_WINTUN_REV} ${WRKSRC}/vendor/golang.zx2c4.com/wintun

post-patch:
	${REINPLACE_CMD} -e s,/etc/nebula,${PREFIX}/etc/${PORTNAME}, \
		-e /dev:/s/nebula1/tun1/ \
		${WRKSRC}/examples/config.yml

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/examples/config.yml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/config.yml.example

.include <bsd.port.mk>
