PORTNAME=		sensu-go
PORTVERSION=		6.9.2
DISTVERSIONPREFIX=	v
PORTREVISION=	16
CATEGORIES=		sysutils

MAINTAINER=		jp+ports@supplntr.io
COMMENT=		Ephemeral infrastructure and distributed applications monitoring
WWW=			https://github.com/sensu/sensu-go/

LICENSE=		APACHE20

USES=			go
USE_RC_SUBR=		sensu-agent
USE_GITHUB=		yes
GH_ACCOUNT=		sensu
GO_TARGET=		sensu-go/cmd/sensu-agent
_BUILD_DATE=		$$(date -u +%Y-%m-%dT%H:%M:%S%z)
VERSIONMOD=		sensu-go/vendor/github.com/sensu/sensu-go/version
GO_BUILDFLAGS=		-ldflags " \
			-X ${VERSIONMOD}.Version=${PORTVERSION} \
			-X ${VERSIONMOD}.BuildDate=${_BUILD_DATE} \
			-X ${VERSIONMOD}.BuildSHA=v${PORTVERSION}"
GH_TUPLE=	\
		AlecAivazis:survey:v2.2.14:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		andybalholm:brotli:v1.0.0:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		ash2k:stager:6e9c7b0eacd4:ash2k_stager/vendor/github.com/ash2k/stager \
		atlassian:gostatsd:af796620006e:atlassian_gostatsd/vendor/github.com/atlassian/gostatsd \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		blang:semver:v4.0.0:blang_semver_v4/vendor/github.com/blang/semver \
		cenkalti:backoff:v4.1.1:cenkalti_backoff_v4/vendor/github.com/cenkalti/backoff/v4 \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:fd7a80b32e1f:coreos_go_systemd/vendor/github.com/coreos/go-systemd \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		dave:jennifer:d8bdbdbee4e1:dave_jennifer/vendor/github.com/dave/jennifer \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dsnet:compress:v0.0.1:dsnet_compress/vendor/github.com/dsnet/compress \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		echlebek:crock:v1.0.1:echlebek_crock/vendor/github.com/echlebek/crock \
		echlebek:timeproxy:v1.0.0:echlebek_timeproxy/vendor/github.com/echlebek/timeproxy \
		emicklei:proto:v1.1.0:emicklei_proto/vendor/github.com/emicklei/proto \
		etcd-io:bbolt:v1.3.6:etcd_io_bbolt/vendor/go.etcd.io/bbolt \
		etcd-io:etcd:v3.5.5:etcd_io_etcd/vendor/go.etcd.io/etcd \
		evanphx:json-patch:v5.1.0:evanphx_json_patch_v5/vendor/github.com/evanphx/json-patch \
		form3tech-oss:jwt-go:v3.2.3:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		frankban:quicktest:v1.7.2:frankban_quicktest/vendor/github.com/frankban/quicktest \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		ghodss:yaml:v1.0.0:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-ini:ini:v1.51.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-resty:resty:v2.5.0:go_resty_resty_v2/vendor/github.com/go-resty/resty/v2 \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-test:deep:v1.0.8:go_test_deep/vendor/github.com/go-test/deep \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v4.0.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:crypto:7b82a4e95df4:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:41bb18bfe9da:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:97ac67df715c:golang_sys/vendor/golang.org/x/sys \
		golang:term:a79de5458b56:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:f8bda1e9f3ba:golang_time/vendor/golang.org/x/time \
		google:btree:v1.0.1:google_btree/vendor/github.com/google/btree \
		google:go-cmp:v0.5.8:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:f16073e35f0c:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		graph-gophers:dataloader:78139374585c:graph_gophers_dataloader/vendor/github.com/graph-gophers/dataloader \
		grpc-ecosystem:go-grpc-middleware:v1.3.0:grpc_ecosystem_go_grpc_middleware/vendor/github.com/grpc-ecosystem/go-grpc-middleware \
		grpc-ecosystem:go-grpc-prometheus:v1.2.0:grpc_ecosystem_go_grpc_prometheus/vendor/github.com/grpc-ecosystem/go-grpc-prometheus \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.41.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		gxed:GoEndian:0f5c6873267e:gxed_goendian/vendor/github.com/gxed/GoEndian \
		gxed:eventfd:80a92cca79a8:gxed_eventfd/vendor/github.com/gxed/eventfd \
		h2non:filetype:v1.0.3:h2non_filetype/vendor/gopkg.in/h2non/filetype.v1 \
		hashicorp:go-version:v1.2.0:hashicorp_go_version/vendor/github.com/hashicorp/go-version \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		influxdata:line-protocol:9aa0e372d097:influxdata_line_protocol/vendor/github.com/influxdata/line-protocol \
		ipfs:go-log:v1.0.4:ipfs_go_log/vendor/github.com/ipfs/go-log \
		ipfs:go-log:v2.0.5:ipfs_go_log_v2/vendor/github.com/ipfs/go-log/v2 \
		jamesdphillips:graphql:v0.8.2:jamesdphillips_graphql/vendor/github.com/graphql-go/graphql \
		jbenet:go-reuseport:15a1cd37f050:jbenet_go_reuseport/vendor/github.com/jbenet/go-reuseport \
		jonboulle:clockwork:v0.2.2:jonboulle_clockwork/vendor/github.com/jonboulle/clockwork \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.9.2:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:pgzip:v1.2.1:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		kr:pty:v1.1.8:kr_pty/vendor/github.com/kr/pty \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		libp2p:go-reuseport:15a1cd37f050:libp2p_go_reuseport \
		libp2p:go-sockaddr:v0.1.0:libp2p_go_sockaddr/vendor/github.com/libp2p/go-sockaddr \
		lufia:plan9stats:39d0f177ccd0:lufia_plan9stats/vendor/github.com/lufia/plan9stats \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.9:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mgutz:ansi:9520e82c474b:mgutz_ansi/vendor/github.com/mgutz/ansi \
		mholt:archiver:44285f7ed244:mholt_archiver_v3/vendor/github.com/mholt/archiver/v3 \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:hashstructure:v1.0.0:mitchellh_hashstructure/vendor/github.com/mitchellh/hashstructure \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		nwaples:rardecode:v1.0.0:nwaples_rardecode/vendor/github.com/nwaples/rardecode \
		olekukonko:tablewriter:v0.0.5:olekukonko_tablewriter/vendor/github.com/olekukonko/tablewriter \
		open-telemetry:opentelemetry-go-contrib:v1.0.0:open_telemetry_opentelemetry_go_contrib/vendor/go.opentelemetry.io/contrib/instrumentation/google.golang.org/grpc/otelgrpc \
		open-telemetry:opentelemetry-go:v1.0.1:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		open-telemetry:opentelemetry-proto-go:v0.9.0:open_telemetry_opentelemetry_proto_go/vendor/go.opentelemetry.io/proto/otlp \
		opentracing:opentracing-go:v1.1.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		pelletier:go-toml:v1.2.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		pierrec:lz4:v3.0.1:pierrec_lz4_v3/vendor/github.com/pierrec/lz4/v3 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		power-devops:perfstat:5aafc221ea8c:power_devops_perfstat/vendor/github.com/power-devops/perfstat \
		prometheus:client_golang:v1.11.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.26.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		sensu:lasr:v1.2.1:sensu_lasr/vendor/github.com/sensu/lasr \
		sensu:sensu-go:types/v0.11.0:sensu_sensu_go_types/vendor/github.com/sensu/sensu-go \
		shirou:gopsutil:v3.21.12:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil/v3 \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		soheilhy:cmux:v0.1.5:soheilhy_cmux/vendor/github.com/soheilhy/cmux \
		spf13:afero:v1.1.2:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:cobra:v1.1.3:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:jwalterweatherman:v1.0.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.7.0:spf13_viper/vendor/github.com/spf13/viper \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tklauser:go-sysconf:v0.3.9:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.3.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		tmc:grpc-websocket-proxy:e5319fda7802:tmc_grpc_websocket_proxy/vendor/github.com/tmc/grpc-websocket-proxy \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.17.0:uber_go_zap/vendor/go.uber.org/zap \
		ulikunitz:xz:v0.5.10:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		willf:pad:b3d780601022:willf_pad/vendor/github.com/willf/pad \
		xi2:xz:48954b6210f8:xi2_xz/vendor/github.com/xi2/xz \
		xiang90:probing:43a291ad63a2:xiang90_probing/vendor/github.com/xiang90/probing \
		yusufpapurcu:wmi:v1.2.2:yusufpapurcu_wmi/vendor/github.com/yusufpapurcu/wmi

post-extract:
	@${MKDIR} ${WRKSRC}/vendor/github.com/libp2p
	@${RLN} ${WRKSRC_jbenet_go_reuseport} ${WRKSRC}/vendor/github.com/libp2p/go-reuseport
	@(cd ${WRKSRC_etcd_io_etcd}/api && ${LN} -s ../api v3)
	@(cd ${WRKSRC_etcd_io_etcd}/pkg && ${LN} -s ../pkg v3)
	@(cd ${WRKSRC_etcd_io_etcd}/client/pkg && ${LN} -s ../pkg v3)
	@${REINPLACE_CMD} -e 's|Version = ""|Version string = "${PORTVERSION}"|g' \
			-e 's|BuildDate string|BuildDate string = "${_BUILD_DATE}"|g' \
			-e 's|BuildSHA string|BuildSHA string = "v${PORTVERSION}"|g' \
			${WRKSRC}/version/version.go

post-install:
	${INSTALL_DATA} ${FILESDIR}/sensu-agent.yml.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
