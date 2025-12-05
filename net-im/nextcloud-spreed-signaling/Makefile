PORTNAME=	nextcloud-spreed-signaling
DISTVERSIONPREFIX=v
DISTVERSION=2.0.2
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Signaling server used for Nextcloud Talk
WWW=		https://github.com/strukturag/nextcloud-spreed-signaling

LICENSE=	AGPLv3

BUILD_DEPENDS=	protoc:devel/protobuf

DEPRECATED=	Uses old go, but try building without USES=go:someversion
EXPIRATION_DATE=2026-01-01

USES=		gmake  go:1.22 go:no_targets
USERS=		signaling
GROUPS=		signaling
USE_RC_SUBR=	ncs_signaling
USE_GITHUB=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	strukturag
GH_TUPLE=	\
		beorn7:perks:v1.0.1:beorn7_perks/vendor/src/github.com/beorn7/perks \
		cenkalti:backoff:v4.2.1:cenkalti_backoff_v4/vendor/src/github.com/cenkalti/backoff/v4 \
		cespare:xxhash:v2.3.0:cespare_xxhash_v2/vendor/src/github.com/cespare/xxhash/v2 \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/src/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/src/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/src/github.com/davecgh/go-spew \
		dlintw:goconf:dcc070983490:dlintw_goconf/vendor/src/github.com/dlintw/goconf \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/src/github.com/dustin/go-humanize \
		etcd-io:bbolt:v1.3.11:etcd_io_bbolt/vendor/src/go.etcd.io/bbolt \
		etcd-io:etcd:v3.5.17:etcd_io_etcd_2/vendor/src/go.etcd.io/etcd \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/src/github.com/fsnotify/fsnotify \
		go-logr:logr:v1.4.2:go_logr_logr/vendor/src/github.com/go-logr/logr \
		go-logr:stdr:v1.2.2:go_logr_stdr/vendor/src/github.com/go-logr/stdr \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/src/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/src/gopkg.in/yaml.v3 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/src/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.5.1:golang_jwt_jwt_v4/vendor/src/github.com/golang-jwt/jwt/v4 \
		golang-jwt:jwt:v5.2.1:golang_jwt_jwt_v5/vendor/src/github.com/golang-jwt/jwt/v5 \
		golang:crypto:v0.31.0:golang_crypto/vendor/src/golang.org/x/crypto \
		golang:net:v0.33.0:golang_net/vendor/src/golang.org/x/net \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/src/github.com/golang/protobuf \
		golang:sys:v0.28.0:golang_sys/vendor/src/golang.org/x/sys \
		golang:text:v0.21.0:golang_text/vendor/src/golang.org/x/text \
		golang:time:v0.8.0:golang_time/vendor/src/golang.org/x/time \
		google:btree:v1.0.1:google_btree/vendor/src/github.com/google/btree \
		google:go-genproto:6ceb2ff114de:google_go_genproto/vendor/src/google.golang.org/genproto \
		google:go-genproto:796eee8c2d53:google_go_genproto_1/vendor/src/google.golang.org/genproto/googleapis/api \
		google:go-genproto:796eee8c2d53:google_go_genproto_2/vendor/src/google.golang.org/genproto/googleapis/rpc \
		google:uuid:v1.6.0:google_uuid/vendor/src/github.com/google/uuid \
		gorilla:mux:v1.8.1:gorilla_mux/vendor/src/github.com/gorilla/mux \
		gorilla:securecookie:v1.1.2:gorilla_securecookie/vendor/src/github.com/gorilla/securecookie \
		gorilla:websocket:v1.5.3:gorilla_websocket/vendor/src/github.com/gorilla/websocket \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/src/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/src/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/src/github.com/grpc-ecosystem/grpc-gateway \
		grpc-ecosystem:grpc-gateway:v2.16.0:grpc_ecosystem_grpc_gateway_v2/vendor/src/github.com/grpc-ecosystem/grpc-gateway/v2 \
		grpc:grpc-go:v1.5.1:grpc_grpc_go_1/vendor/src/google.golang.org/grpc/cmd/protoc-gen-go-grpc \
		grpc:grpc-go:v1.69.4:grpc_grpc_go/vendor/src/google.golang.org/grpc \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/src/github.com/jonboulle/clockwork \
		josharian:intern:v1.0.0:josharian_intern/vendor/src/github.com/josharian/intern \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/src/github.com/json-iterator/go \
		klauspost:compress:v1.17.11:klauspost_compress/vendor/src/github.com/klauspost/compress \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/src/sigs.k8s.io/yaml \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/src/github.com/kylelemons/godebug \
		mailru:easyjson:v0.9.0:mailru_easyjson/vendor/src/github.com/mailru/easyjson \
		marcw:cachecontrol:30341fe9a7d5:marcw_cachecontrol/vendor/src/github.com/marcw/cachecontrol \
		minio:highwayhash:v1.0.3:minio_highwayhash/vendor/src/github.com/minio/highwayhash \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/src/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/src/github.com/modern-go/reflect2 \
		munnerz:goautoneg:a7dc8b61c822:munnerz_goautoneg/vendor/src/github.com/munnerz/goautoneg \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/src/gopkg.in/natefinch/lumberjack.v2 \
		nats-io:jwt:v2.7.3:nats_io_jwt_v2/vendor/src/github.com/nats-io/jwt \
		nats-io:nats-server:v2.10.24:nats_io_nats_server_v2/vendor/src/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.38.0:nats_io_nats_go/vendor/src/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.4.9:nats_io_nkeys/vendor/src/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/src/github.com/nats-io/nuid \
		notedit:janus-go:10eb8b95d1a0:notedit_janus_go/vendor/src/github.com/notedit/janus-go \
		open-telemetry:opentelemetry-go-contrib:v1.21.0:open_telemetry_opentelemetry_go_contrib/vendor/src/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc \
		open-telemetry:opentelemetry-go:v1.20.0:open_telemetry_opentelemetry_go_1/vendor/src/go.opentelemetry.io/otel/exporters/otlp/otlptrace \
		open-telemetry:opentelemetry-go:v1.31.0:open_telemetry_opentelemetry_go/vendor/src/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v1.0.0:open_telemetry_opentelemetry_proto_go/vendor/src/go.opentelemetry.io/proto/otlp \
		oschwald:maxminddb-golang:v1.13.1:oschwald_maxminddb_golang/vendor/src/github.com/oschwald/maxminddb-golang \
		pion:randutil:v0.1.0:pion_randutil/vendor/src/github.com/pion/randutil \
		pion:sdp:v3.0.10:pion_sdp_v3/vendor/src/github.com/pion/sdp/v3 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/src/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.20.5:prometheus_client_golang/vendor/src/github.com/prometheus/client_golang \
		prometheus:client_model:v0.6.1:prometheus_client_model/vendor/src/github.com/prometheus/client_model \
		prometheus:common:v0.55.0:prometheus_common/vendor/src/github.com/prometheus/common \
		prometheus:procfs:v0.15.1:prometheus_procfs/vendor/src/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.36.3:protocolbuffers_protobuf_go/vendor/src/google.golang.org/protobuf \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/src/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/src/github.com/soheilhy/cmux \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/src/github.com/spf13/pflag \
		stretchr:testify:v1.10.0:stretchr_testify/vendor/src/github.com/stretchr/testify \
		tmc:grpc-websocket-proxy:e5319fda7802:tmc_grpc_websocket_proxy/vendor/src/github.com/tmc/grpc-websocket-proxy \
		uber-go:multierr:v1.10.0:uber_go_multierr/vendor/src/go.uber.org/multierr \
		uber-go:zap:v1.27.0:uber_go_zap/vendor/src/go.uber.org/zap \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/src/github.com/xiang90/probing

MAKE_ENV=	${GOENV}\
		GO111MODULE=off \
		GOPATH="${WRKSRC}/vendor"
post-extract:
	${MKDIR} ${WRKSRC}/vendor/src/go.etcd.io/etcd/client/pkg/v3
	${MKDIR} ${WRKSRC}/vendor/src/go.etcd.io/etcd/api/v3
	${FIND} ${WRKSRC}/vendor/src/go.etcd.io/etcd/client/pkg -type d  -not -name  v3  -exec ${SH} -c 'ln -s  `realpath {}` ${WRKSRC}/vendor/src/go.etcd.io/etcd/client/pkg/v3/`basename {}`'  \;
	${FIND} ${WRKSRC}/vendor/src/go.etcd.io/etcd/api -type d  -not -name  v3  -exec ${SH} -c 'ln -s  `realpath {}` ${WRKSRC}/vendor/src/go.etcd.io/etcd/api/v3/`basename {}`'  \;
	${CP} ${FILESDIR}/version.txt ${WRKSRC}/version.txt
	${MKDIR} ${WRKDIR}/${PORTNAME}-${DISTVERSION}/vendor/src/github.com/strukturag
	${LN} -s ${WRKDIR}/${PORTNAME}-${DISTVERSION}/ ${WRKDIR}/${PORTNAME}-${DISTVERSION}/vendor/src/github.com/strukturag/${PORTNAME}
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
