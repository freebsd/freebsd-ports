PORTNAME=	nut_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	16
CATEGORIES=	sysutils

MAINTAINER=	bsd@j-star.org
COMMENT=	Prometheus exporter for the Network UPS Tools server
WWW=		https://github.com/DRuggeri/nut_exporter

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	DRuggeri
GH_TUPLE=	alecthomas:kingpin:v2.3.2:alecthomas_kingpin_v2/vendor/github.com/alecthomas/kingpin/v2 \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.7.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.8.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.6.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sync:v0.1.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.8.0:golang_text/vendor/golang.org/x/text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		prometheus:client_golang:v1.14.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.3.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.41.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:feef77d71811:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.9.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.28.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robbiet480:go.nut:bd8f121e1fa1:robbiet480_go_nut/vendor/github.com/robbiet480/go.nut \
		rogpeppe:go-internal:v1.9.0:rogpeppe_go_internal/vendor/github.com/rogpeppe/go-internal \
		xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2
USE_RC_SUBR=	nut_exporter
PLIST_FILES=	bin/nut_exporter

.include <bsd.port.mk>
