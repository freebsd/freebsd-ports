# $FreeBSD$

PORTNAME=	seaweedfs
DISTVERSION=	2.29
CATEGORIES=	net sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Distributed Object Store and Filesystem

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
USE_GITLAB=	nodefault
GH_ACCOUNT=	chrislusf

GH_TUPLE=	\
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.9.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		DataDog:zstd:796139022798:datadog_zstd/vendor/github.com/DataDog/zstd \
		OneOfOne:xxhash:v1.2.2:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		Shopify:sarama:v1.23.1:shopify_sarama/vendor/github.com/Shopify/sarama \
		andybalholm:brotli:v1.0.0:andybalholm_brotli/vendor/github.com/andybalholm/brotli \
		aws:aws-sdk-go:v1.34.30:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		buraksezer:consistent:693edf70fd72:buraksezer_consistent/vendor/github.com/buraksezer/consistent \
		census-instrumentation:opencensus-go:v0.22.4:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		chrislusf:raft:v1.0.4:chrislusf_raft/vendor/github.com/chrislusf/raft \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.0.0:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		disintegration:imaging:v1.6.2:disintegration_imaging/vendor/github.com/disintegration/imaging \
		dominikh:go-tools:v0.0.1-2020.1.4:dominikh_go_tools/vendor/honnef.co/go/tools \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		etcd-io:etcd:262c93980547:etcd_io_etcd/vendor/go.etcd.io/etcd \
		facebookgo:clock:600d898af40a:facebookgo_clock/vendor/github.com/facebookgo/clock \
		facebookgo:stats:1b76add642e4:facebookgo_stats/vendor/github.com/facebookgo/stats \
		fclairamb:ftpserverlib:v0.8.0:fclairamb_ftpserverlib/vendor/github.com/fclairamb/ftpserverlib \
		fsnotify:fsnotify:v1.4.9:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-errors:errors:v1.1.1:go_errors_errors/vendor/github.com/go-errors/errors \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-redis:redis:v8.4.4:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.3.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-zookeeper:zk:v1.0.2:go_zookeeper_zk/vendor/github.com/go-zookeeper/zk \
		gocql:gocql:e163eff7a8c6:gocql_gocql/vendor/github.com/gocql/gocql \
		gogo:protobuf:28a6bbf47e48:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:75b288015ac9:golang_crypto/vendor/golang.org/x/crypto \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:image:58c23975cae1:golang_image/vendor/golang.org/x/image \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:c7110b5ffcbb:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.4.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:30421366ff76:golang_sync/vendor/golang.org/x/sync \
		golang:sys:fb209a7c41cd:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:tools:1b747fd94509:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:9bdfabe68543:golang_xerrors/vendor/golang.org/x/xerrors \
		google:btree:v1.0.0:google_btree/vendor/github.com/google/btree \
		google:go-cloud:v0.20.0:google_go_cloud/vendor/gocloud.dev \
		google:go-cmp:v0.5.4:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:7c474a2e3482:google_go_genproto/vendor/google.golang.org/genproto \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		google:wire:v0.4.0:google_wire/vendor/github.com/google/wire \
		googleapis:gax-go:v2.0.2:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2 \
		googleapis:google-api-go-client:v0.26.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:pubsub/v1.3.1:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:storage/v1.9.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.58.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.7.4:gorilla_mux/vendor/github.com/gorilla/mux \
		grpc:grpc-go:v1.29.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.3.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		karlseguin:ccache:v2.0.7:karlseguin_ccache_v2/vendor/github.com/karlseguin/ccache/v2 \
		klauspost:compress:v1.10.9:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:crc32:v1.2.0:klauspost_crc32/vendor/github.com/klauspost/crc32 \
		klauspost:reedsolomon:v1.9.2:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		konsorten:go-windows-terminal-sequences:v1.0.2:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kurin:blazer:v0.5.3:kurin_blazer/vendor/github.com/kurin/blazer \
		lib:pq:v1.2.0:lib_pq/vendor/github.com/lib/pq \
		magiconair:properties:v1.8.1:magiconair_properties/vendor/github.com/magiconair/properties \
		mailru:easyjson:v0.7.1:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.3.2:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		nats-io:jwt:v1.0.1:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:nats.go:v1.10.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.2.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		olivere:elastic:v7.0.19:olivere_elastic_v7/vendor/github.com/olivere/elastic/v7 \
		open-telemetry:opentelemetry-go:v0.15.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		pelletier:go-toml:v1.4.0:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		peterh:liner:v1.1.0:peterh_liner/vendor/github.com/peterh/liner \
		pierrec:lz4:v2.2.7:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.3.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.1.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.7.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.24.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rakyll:statik:v0.1.7:rakyll_statik/vendor/github.com/rakyll/statik \
		rcrowley:go-metrics:cac0b30c2563:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		seaweedfs:fuse:v1.1.1:seaweedfs_fuse/vendor/github.com/seaweedfs/fuse \
		seaweedfs:goexif:v1.0.2:seaweedfs_goexif/vendor/github.com/seaweedfs/goexif \
		sirupsen:logrus:v1.5.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		skip2:go-qrcode:da1b6568686e:skip2_go_qrcode/vendor/github.com/skip2/go-qrcode \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		spf13:afero:v1.3.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.3.0:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.3:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.4.0:spf13_viper/vendor/github.com/spf13/viper \
		streadway:amqp:1c71cc93ed71:streadway_amqp/vendor/github.com/streadway/amqp \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		syndtr:goleveldb:v1.0.0:syndtr_goleveldb/vendor/github.com/syndtr/goleveldb \
		tecbot:gorocksdb:f0fad39f321c:tecbot_gorocksdb/vendor/github.com/tecbot/gorocksdb \
		tidwall:gjson:v1.3.2:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tsuna:gohbase:348991136365:tsuna_gohbase/vendor/github.com/tsuna/gohbase \
		uber-go:atomic:v1.6.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.5.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.14.1:uber_go_zap/vendor/go.uber.org/zap \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		valyala:fasthttp:v1.20.0:valyala_fasthttp/vendor/github.com/valyala/fasthttp \
		viant:ptrie:v0.3.0:viant_ptrie/vendor/github.com/viant/ptrie \
		viant:toolbox:v0.33.2:viant_toolbox/vendor/github.com/viant/toolbox \
		willf:bitset:v1.1.10:willf_bitset/vendor/github.com/willf/bitset \
		willf:bloom:v2.0.3:willf_bloom/vendor/github.com/willf/bloom \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep

GL_TUPLE=	cznic:b:e2c6d3c5e5f25b4f5a667952d78e934528620d0f:cznic_b/vendor/modernc.org/b

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RM} -r ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2
	@${RLN} ${WRKSRC_googleapis_gax_go_v2}/v2 ${WRKSRC}/vendor/github.com/googleapis/gax-go/v2

post-build:
.for cfg in master filer security replication notification
	${WRKDIR}/bin/weed scaffold -config ${cfg} -output ${WRKDIR}/
.endfor

post-install:
	${MKDIR} \
	    ${STAGEDIR}/var/db/${PORTNAME} \
	    ${STAGEDIR}/var/log/${PORTNAME} \
	    ${STAGEDIR}${ETCDIR}
.for cfg in master filer security replication notification
	${INSTALL_DATA} ${WRKDIR}/${cfg}.toml \
	    ${STAGEDIR}${ETCDIR}/${cfg}.toml.sample
.endfor

GO_TARGET=	./weed:${PREFIX}/sbin/weed
CGO_CFLAGS=	-I.

USE_RC_SUBR=	seaweedfs

USERS=		seaweedfs
GROUPS=		seaweedfs

SUB_FILES=	pkg-message

.include	<bsd.port.mk>
