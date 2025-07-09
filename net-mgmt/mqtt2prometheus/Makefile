PORTNAME=		mqtt2prometheus
DISTVERSIONPREFIX=	v
DISTVERSION=		0.1.7
PORTREVISION=	5
CATEGORIES=		net-mgmt

MAINTAINER=	manu@FreeBSD.org
COMMENT=	Export MQTT metrics to prometheus
WWW=		https://github.com/hikhvar/mqtt2prometheus/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go

USE_GITHUB=	yes
GH_ACCOUNT=	hikhvar
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		eclipse:paho.mqtt.golang:v1.3.5:paho/vendor/github.com/eclipse/paho.mqtt.golang \
		go-kit:kit:v0.10.0:go_kit_kit/vendor/github.com/go-kit/kit \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		patrickmn:go-cache:v2.1.0:patrickmn_go_cache/vendor/github.com/patrickmn/go-cache \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		prometheus:client_golang:v1.7.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:exporter-toolkit:v0.5.1:prometheus_exporter_toolkit/vendor/github.com/prometheus/exporter-toolkit \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		uber-go:zap:v1.16.0:uber_go_zap/vendor/go.uber.org/zap \
		thedevsaddam:gojsonq:v2.5.2:thedevsaddam_gojsonq_v2/vendor/github.com/thedevsaddam/gojsonq/v2 \
		golang:net:4c5254603344:golang_net/vendor/golang.org/x/net \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		golang:protobuf:v1.4.2:protobuf/vendor/github.com/golang/protobuf \
		golang:crypto:5f87f3452ae9:crypto/vendor/golang.org/x/crypto \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:multierr/vendor/go.uber.org/multierr \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		matttproud:golang_protobuf_extensions:v1.0.1:extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mwitkow:go-conntrack:2f068394615f:mwitkow_go_conntrack/vendor/github.com/mwitkow/go-conntrack \
		golang:sys:v0.6.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		protocolbuffers:protobuf-go:v1.23.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf

GO_TARGET=	./cmd:${PORTNAME}

post-extract:
	@${MKDIR} ${GO_WRKSRC:H}
	@${LN} -sf ${WRKSRC} ${GO_WRKSRC}
	@${MKDIR} ${WRKSRC}/vendor/github.com/hikhvar/mqtt2prometheus/
	@${LN} -s ${WRKSRC}/pkg ${WRKSRC}/vendor/github.com/hikhvar/mqtt2prometheus/pkg

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mqtt2prometheus/
	${INSTALL_DATA} ${WRKSRC}/config.yaml.dist ${STAGEDIR}${PREFIX}/etc/mqtt2prometheus/
	${INSTALL_SCRIPT} ${FILESDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/etc/rc.d

.include <bsd.port.mk>
