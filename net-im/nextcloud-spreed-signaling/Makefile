PORTNAME=	nextcloud-spreed-signaling
DISTVERSIONPREFIX=v
DISTVERSION=	2.0.4
CATEGORIES=	net-im

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Signaling server used for Nextcloud Talk
WWW=		https://github.com/strukturag/nextcloud-spreed-signaling

LICENSE=	AGPLv3

BUILD_DEPENDS=	protoc:devel/protobuf \
		bash:shells/bash


USES=		gmake go:no_targets
USERS=		signaling
GROUPS=		signaling
USE_RC_SUBR=	ncs_signaling
USE_GITHUB=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	strukturag
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/src/github.com/beorn7/perks \
		cenkalti:backoff:v4.3.0:cenkalti_backoff_v4/vendor/src/github.com/cenkalti/backoff/v4 \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/src/github.com/cespare/xxhash/v2 \
		coreos:go-semver:v0.3.1:coreos_go_semver/vendor/src/github.com/coreos/go-semver \
		coreos:go-systemd:v22.5.0:coreos_go_systemd_v22/vendor/src/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/src/github.com/davecgh/go-spew \
		dlintw:goconf:dcc070983490:dlintw_goconf/vendor/src/github.com/dlintw/goconf \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/src/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.4.2:etcd_io_bbolt/vendor/src/go.etcd.io/bbolt \
		etcd-io:etcd:v3.6.4:etcd_io_etcd/vendor/go.etcd.io/etcd/api/v3 \
		etcd-io:etcd:v3.6.4:etcd_io_etcd_2/vendor/src/go.etcd.io/etcd \
		etcd-io:raft:v3.6.0:etcd_io_raft/vendor/src/go.etcd.io/raft/v3 \
		fsnotify:fsnotify:v1.9.0:fsnotify_fsnotify/vendor/src/github.com/fsnotify/fsnotify \
		go-logr:logr:v1.4.3:go_logr_logr/vendor/src/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/src/github.com/go-logr/stdr \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/src/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/src/github.com/gogo/protobuf \
		golang-jwt:jwt:v5.3.0:golang_jwt_jwt_v5/vendor/src/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.41.0:golang_crypto/vendor/src/golang.org/x/crypto \
		golang:net:v0.42.0:golang_net/vendor/src/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/src/github.com/golang/protobuf \
		golang:sys:v0.35.0:golang_sys/vendor/src/golang.org/x/sys \
		golang:text:v0.28.0:golang_text/vendor/src/golang.org/x/text \
		golang:time:v0.12.0:golang_time/vendor/src/golang.org/x/time \
		google:btree:v1.1.3:google_btree/vendor/src/github.com/google/btree \
		google:go-cmp:v0.7.0:google_go_cmp/vendor/src/github.com/google/go-cmp \
		google:go-genproto:200df99c418a:google_go_genproto/vendor/src/google.golang.org/genproto \
		google:go-tpm:v0.9.5:google_go_tpm/vendor/src/github.com/google/go-tpm \
		google:uuid:v1.6.0:google_uuid/vendor/src/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/src/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.2:gorilla_securecookie/vendor/src/github.com/gorilla/securecookie \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/src/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:7da22cf3f3d3:grpc_ecosystem_go_grpc_middleware_prometheus/vendor/src/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-middleware:v2.1.0:grpc_ecosystem_go_grpc_middleware_v2/vendor/src/github.com/grpc-ecosystem/go-grpc-middleware/v2 \
		grpc-ecosystem:grpc-gateway:v2.26.3:grpc_ecosystem_grpc_gateway_v2/vendor/src/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.5.1:grpc_grpc_go_1/vendor/src/google.golang.org/grpc/cmd/protoc-gen-go-grpc \
		grpc:grpc-go:v1.74.2:grpc_grpc_go/vendor/src/google.golang.org/grpc \
		jonboulle:clockwork:v0.5.0:jonboulle_clockwork/vendor/src/github.com/jonboulle/clockwork \
		josharian:intern:v1.0.0:josharian_intern/vendor/src/github.com/josharian/intern \
		klauspost:compress:v1.18.0:klauspost_compress/vendor/src/github.com/klauspost/compress \
		kubernetes-sigs:json:c049b76a60c6:kubernetes_sigs_json/vendor/src/sigs.k8s.io/json \
		kubernetes-sigs:yaml:v1.4.0:kubernetes_sigs_yaml/vendor/src/sigs.k8s.io/yaml \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/src/github.com/kylelemons/godebug \
		mailru:easyjson:v0.9.0:mailru_easyjson/vendor/src/github.com/mailru/easyjson \
		minio:highwayhash:v1.0.3:minio_highwayhash/vendor/src/github.com/minio/highwayhash \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/src/github.com/munnerz/goautoneg \
		natefinch:lumberjack:v2.2.1:natefinch_lumberjack/vendor/src/gopkg.in/natefinch/lumberjack.v2 \
		nats-io:jwt:v2.7.4:nats_io_jwt_v2/vendor/src/github.com/nats-io/jwt \
		nats-io:nats-server:v2.11.8:nats_io_nats_server_v2/vendor/src/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.44.0:nats_io_nats_go/vendor/src/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.4.11:nats_io_nkeys/vendor/src/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/src/github.com/nats-io/nuid \
		notedit:janus-go:10eb8b95d1a0:notedit_janus_go/vendor/src/github.com/notedit/janus-go \
		open-telemetry:opentelemetry-go-contrib:v1.34.0:open_telemetry_opentelemetry_go_contrib/vendor/src/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc \
		open-telemetry:opentelemetry-go-instrumentation:sdk/v1.1.0:open_telemetry_opentelemetry_go_instrumentation/vendor/src/go.opentelemetry.io/auto/sdk \
		open-telemetry:opentelemetry-go:v1.34.0:open_telemetry_opentelemetry_go_1/vendor/src/go.opentelemetry.io/otel/exporters/otlp/otlptrace \
		open-telemetry:opentelemetry-go:v1.36.0:open_telemetry_opentelemetry_go/vendor/src/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v1.5.0:open_telemetry_opentelemetry_proto_go/vendor/src/go.opentelemetry.io/proto/otlp \
		oschwald:maxminddb-golang:v1.13.1:oschwald_maxminddb_golang/vendor/src/github.com/oschwald/maxminddb-golang \
		pion:dtls:v3.0.6:pion_dtls_v3/vendor/src/github.com/pion/dtls/v3 \
		pion:ice:v4.0.10:pion_ice_v4/vendor/src/github.com/pion/ice/v4 \
		pion:logging:v0.2.3:pion_logging/vendor/src/github.com/pion/logging \
		pion:mdns:v2.0.7:pion_mdns_v2/vendor/src/github.com/pion/mdns/v2 \
		pion:randutil:v0.1.0:pion_randutil/vendor/src/github.com/pion/randutil \
		pion:sdp:v3.0.15:pion_sdp_v3/vendor/src/github.com/pion/sdp/v3 \
		pion:stun:v3.0.0:pion_stun_v3/vendor/src/github.com/pion/stun/v3 \
		pion:transport:v3.0.7:pion_transport_v3/vendor/src/github.com/pion/transport/v3 \
		pion:turn:v4.0.0:pion_turn_v4/vendor/src/github.com/pion/turn/v4 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/src/github.com/pmezard/go-difflib \
		pquerna:cachecontrol:v0.2.0:pquerna_cachecontrol/vendor/src/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.23.0:prometheus_client_golang/vendor/src/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.2:prometheus_client_model/vendor/src/github.com/prometheus/client_model \
		prometheus:common:v0.65.0:prometheus_common/vendor/src/github.com/prometheus/common \
		prometheus:procfs:v0.16.1:prometheus_procfs/vendor/src/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.7:protocolbuffers_protobuf_go/vendor/src/google.golang.org/protobuf \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/src/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/src/github.com/soheilhy/cmux \
		spf13:pflag:v1.0.6:spf13_pflag/vendor/src/github.com/spf13/pflag \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/src/github.com/stretchr/testify \
		tmc:grpc-websocket-proxy:e5319fda7802:tmc_grpc_websocket_proxy/vendor/src/github.com/tmc/grpc-websocket-proxy \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/src/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/src/go.uber.org/zap \
		wlynxg:anet:v0.0.5:wlynxg_anet/vendor/src/github.com/wlynxg/anet \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/src/github.com/xiang90/probing

MAKE_ENV=	${GOENV}\
		GO111MODULE=off \
		GOPATH="${WRKSRC}/vendor"
post-extract:
	${MKDIR} ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/vendor/src/github.com/strukturag
	${LN} -s ${WRKSRC} ${WRKSRC}/vendor/src/github.com/strukturag/${PORTNAME}
	${CP} ${FILESDIR}/version.txt ${WRKSRC}/version.txt
do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE}
post-patch:
	@${REINPLACE_CMD} 's|%%DISTVERSION%%|${PORTVERSION}|g' ${WRKSRC}/version.txt
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ncs-signaling
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ncs-proxy
do-install:
	${INSTALL} -d $(STAGEDIR)$(PREFIX)/etc/ncs/
	${INSTALL} -m 644 ${WRKSRC}/server.conf.in $(STAGEDIR)$(PREFIX)/etc/ncs/server.conf.sample
	${INSTALL} -m 644 ${WRKSRC}/proxy.conf.in $(STAGEDIR)$(PREFIX)/etc/ncs/proxy.conf.sample
	${INSTALL} -m 644 ${WRKSRC}/gnatsd.conf $(STAGEDIR)$(PREFIX)/etc/ncs/gnatsd.conf.sample
	${INSTALL} -m 755 ${WRKSRC}/bin/signaling $(STAGEDIR)$(PREFIX)/bin/ncs-signaling
	${INSTALL} -m 755 ${WRKSRC}/bin/proxy $(STAGEDIR)$(PREFIX)/bin/ncs-proxy

.include <bsd.port.mk>
