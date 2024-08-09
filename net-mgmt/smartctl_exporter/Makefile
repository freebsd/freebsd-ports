PORTNAME=		smartctl_exporter
PORTVERSION=		0.12.0
DISTVERSIONPREFIX=	v
PORTREVISION=	6
CATEGORIES=		net-mgmt

MAINTAINER=		delphij@FreeBSD.org
COMMENT=		Prometheus metrics exporter for smartctl
WWW=			https://github.com/prometheus-community/smartctl_exporter

LICENSE=		LGPL3

USES=			go:modules
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
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.18.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.20.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.16.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.5.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.16.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		prometheus:client_golang:v1.19.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.5.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.48.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.11.0:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.12.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.32.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		tidwall:gjson:v1.17.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2

pre-patch:
	${REINPLACE_CMD} -i '' -e 's|/usr/sbin/smartctl|${LOCALBASE}/sbin/smartctl|g' \
		${WRKSRC}/README.md ${WRKSRC}/main.go

.include <bsd.port.mk>
