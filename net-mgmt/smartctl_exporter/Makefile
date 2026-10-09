PORTNAME=	smartctl_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.0
CATEGORIES=	net-mgmt

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Prometheus metrics exporter for smartctl
WWW=		https://github.com/prometheus-community/smartctl_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	smartctl:sysutils/smartmontools

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus-community
GH_TUPLE=	alecthomas:kingpin:v2.4.0:alecthomas_kingpin_v2/vendor/github.com/alecthomas/kingpin/v2 \
		alecthomas:units:0f3dac36c52b:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-systemd:v22.7.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		golang-jwt:jwt:v5.3.1:golang_jwt_jwt_v5/vendor/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.57.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.59.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.37.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.23.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.48.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.42.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.15.0:golang_time/vendor/golang.org/x/time \
		google:uuid:v1.6.0:google_uuid/vendor/github.com/google/uuid \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		mdlayher:socket:v0.6.0:mdlayher_socket/vendor/github.com/mdlayher/socket \
		mdlayher:vsock:v1.3.0:mdlayher_vsock/vendor/github.com/mdlayher/vsock \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		prometheus:client_golang:v1.24.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.3:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.72.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.20.0:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.21.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.12:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		tidwall:gjson:v1.19.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2 \
		yaml:go-yaml:v2.4.4:yaml_go_yaml/vendor/go.yaml.in/yaml/v2
USE_RC_SUBR=	${PORTNAME}

GO_TARGET=	${PORTNAME}:${PREFIX}/libexec/${PORTNAME}
GO_LDFLAGS=	-X github.com/prometheus/common/version.Version=${DISTVERSION}

PLIST_FILES=	libexec/${PORTNAME}

post-extract:
	${INSTALL_DATA} ${FILESDIR}/modules.txt ${WRKSRC}/vendor/modules.txt

post-patch:
	${REINPLACE_CMD} -e 's|/usr/sbin/smartctl|${LOCALBASE}/sbin/smartctl|g' \
		${WRKSRC}/main.go

# Maintenance target: regenerate files/modules.txt and print the matching
# GH_TUPLE.  Requires network access.  Run after updating DISTVERSION.
generate-modules-txt: gomod-vendor
	${INSTALL_DATA} ${WRKSRC}/vendor/modules.txt ${FILESDIR}/modules.txt

.include <bsd.port.mk>
