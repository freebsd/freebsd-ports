PORTNAME=	pushgateway
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	nulldutra@proton.me
COMMENT=	Prometheus push acceptor for ephemeral and batch jobs
WWW=		https://github.com/prometheus/pushgateway

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
GH_TUPLE=	\
		alecthomas:kingpin:v2.3.2:alecthomas_kingpin_v2/vendor/github.com/alecthomas/kingpin/v2 \
		alecthomas:units:b94a6e3cc137:alecthomas_units/vendor/github.com/alecthomas/units \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		cespare:xxhash:v2.2.0:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		go-kit:log:v0.2.1:go_kit_log/vendor/github.com/go-kit/log \
		go-logfmt:logfmt:v0.5.1:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.8.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.10.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.8.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:v0.2.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.8.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.9.0:golang_text/vendor/golang.org/x/text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		julienschmidt:httprouter:v1.3.0:julienschmidt_httprouter/vendor/github.com/julienschmidt/httprouter \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		matttproud:golang_protobuf_extensions:v1.0.4:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		prometheus:client_golang:v1.16.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.4.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.44.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.10.0:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.10.1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.31.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		shurcooL:httpfs:8d4bc4ba7749:shurcool_httpfs/vendor/github.com/shurcooL/httpfs \
		shurcooL:vfsgen:0000e147ea92:shurcool_vfsgen/vendor/github.com/shurcooL/vfsgen \
		xhit:go-str2duration:v2.1.0:xhit_go_str2duration_v2/vendor/github.com/xhit/go-str2duration/v2

USE_RC_SUBR=	pushgateway

USERS=		prometheus
GROUPS=		prometheus

PLIST_FILES=	bin/pushgateway

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GMAKE} test)

.include <bsd.port.mk>
