PORTNAME=		smartctl_exporter
PORTVERSION=		0.14.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=		net-mgmt

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		Prometheus metrics exporter for smartctl
WWW=			https://github.com/prometheus-community/smartctl_exporter

LICENSE=		APACHE20

USES=			go:1.23,modules
USE_GITHUB=		yes
GH_ACCOUNT=		prometheus-community

USE_RC_SUBR=		smartctl_exporter
RUN_DEPENDS+=		smartctl:sysutils/smartmontools
GO_MODULES=		github.com/prometheus-community/smartctl_exporter
GO_TARGET=		${PORTNAME}:${PREFIX}/libexec/${PORTNAME}
PLIST_FILES=		libexec/${PORTNAME}

GH_TUPLE=	\
		alecthomas:kingpin:v2.4.0:alecthomas_kingpin_v2/vendor/github.com/alecthomas/kingpin/v2 \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:v0.33.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.35.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.25.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:v0.11.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.30.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.22.0:golang_text/vendor/golang.org/x/text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		klauspost:compress:v1.17.11:klauspost_compress/vendor/github.com/klauspost/compress \
		mdlayher:socket:v0.4.1:mdlayher_socket/vendor/github.com/mdlayher/socket \
		mdlayher:vsock:v1.2.1:mdlayher_vsock/vendor/github.com/mdlayher/vsock \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/github.com/munnerz/goautoneg \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		prometheus:client_golang:v1.21.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.63.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.14.0:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.5:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		tidwall:gjson:v1.18.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2

pre-patch:
	${REINPLACE_CMD} -i '' -e 's|/usr/sbin/smartctl|${LOCALBASE}/sbin/smartctl|g' \
		${WRKSRC}/README.md ${WRKSRC}/main.go

.include <bsd.port.mk>
