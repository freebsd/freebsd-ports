PORTNAME=	nextcloud-spreed-signaling
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	net-im

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Signaling server used for Nextcloud Talk

LICENSE=	AGPLv3

USES=		gmake go:no_targets

USERS=		signaling
GROUPS=		signaling

USE_RC_SUBR=	ncs_signaling

USE_GITHUB=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	strukturag
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/src/github.com/beorn7/perks \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/src/github.com/cespare/xxhash/v2 \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/src/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/src/github.com/coreos/go-systemd/v22 \
		dlintw:goconf:dcc070983490:dlintw_goconf/vendor/src/github.com/dlintw/goconf \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/src/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/src/go.etcd.io/bbolt \
		etcd-io:etcd:v3.5.4:etcd_io_etcd/vendor/src/go.etcd.io/etcd \
		form3tech-oss:jwt-go:v3.2.3:form3tech_oss_jwt_go/vendor/src/github.com/form3tech-oss/jwt-go \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/src/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/src/github.com/gogo/protobuf \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/src/github.com/golang-jwt/jwt \
		golang:crypto:3147a52a75dd:golang_crypto/vendor/src/golang.org/x/crypto \
		golang:net:69e39bad7dc2:golang_net/vendor/src/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/src/github.com/golang/protobuf \
		golang:sys:36772127a21f:golang_sys/vendor/src/golang.org/x/sys \
		golang:text:v0.3.6:golang_text/vendor/src/golang.org/x/text \
		golang:time:f0f3c7e86c11:golang_time/vendor/src/golang.org/x/time \
		google:btree:v1.0.1:google_btree/vendor/src/github.com/google/btree \
		google:go-genproto:f16073e35f0c:google_go_genproto/vendor/src/google.golang.org/genproto \
		google:uuid:v1.3.0:google_uuid/vendor/src/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/src/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.1:gorilla_securecookie/vendor/src/github.com/gorilla/securecookie \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/src/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/src/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/src/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/src/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.38.0:grpc_grpc_go/vendor/src/google.golang.org/grpc \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/src/github.com/jonboulle/clockwork \
		josharian:intern:v1.0.0:josharian_intern/vendor/src/github.com/josharian/intern \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/src/github.com/json-iterator/go \
		klauspost:compress:v1.14.4:klauspost_compress/vendor/src/github.com/klauspost/compress \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/src/sigs.k8s.io/yaml \
		mailru:easyjson:v0.7.7:mailru_easyjson/vendor/src/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/src/github.com/matttproud/golang_protobuf_extensions \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/src/github.com/minio/highwayhash \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/src/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/src/github.com/modern-go/reflect2 \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/src/gopkg.in/natefinch/lumberjack.v2 \
		nats-io:jwt:442af02fd36a:nats_io_jwt_v2/vendor/src/github.com/nats-io/jwt \
		nats-io:nats-server:v2.8.4:nats_io_nats_server_v2/vendor/src/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.16.0:nats_io_nats_go/vendor/src/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/src/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/src/github.com/nats-io/nuid \
		notedit:janus-go:10eb8b95d1a0:notedit_janus_go/vendor/src/github.com/notedit/janus-go \
		open-telemetry:opentelemetry-go-contrib:v0.20.0:open_telemetry_opentelemetry_go_contrib/vendor/src/go.opentelemetry.io/contrib \
		open-telemetry:opentelemetry-go:v0.20.0:open_telemetry_opentelemetry_go/vendor/src/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v0.7.0:open_telemetry_opentelemetry_proto_go/vendor/src/go.opentelemetry.io/proto/otlp \
		oschwald:maxminddb-golang:v1.9.0:oschwald_maxminddb_golang/vendor/src/github.com/oschwald/maxminddb-golang \
		pion:sdp:v1.3.0:pion_sdp/vendor/src/github.com/pion/sdp \
		pkg:errors:v0.9.1:pkg_errors/vendor/src/github.com/pkg/errors \
		prometheus:client_golang:v1.12.2:prometheus_client_golang/vendor/src/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/src/github.com/prometheus/client_model \
		prometheus:common:v0.32.1:prometheus_common/vendor/src/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/src/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/src/google.golang.org/protobuf \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/src/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/src/github.com/soheilhy/cmux \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/src/github.com/spf13/pflag \
		tmc:grpc-websocket-proxy:e5319fda7802:tmc_grpc_websocket_proxy/vendor/src/github.com/tmc/grpc-websocket-proxy \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/src/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/src/go.uber.org/multierr \
		uber-go:zap:v1.17.0:uber_go_zap/vendor/src/go.uber.org/zap \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/src/github.com/xiang90/probing
MAKE_ENV=	${GO_ENV}
post-extract:
	${MKDIR} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/vendor/src/github.com/strukturag
	${LN} -s ${WRKDIR}/${PORTNAME}-${DISTVERSION}/ ${WRKDIR}/${PORTNAME}-${DISTVERSION}/vendor/src/github.com/strukturag/${PORTNAME}
.include <bsd.port.mk>
