# $FreeBSD$

PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

BUILD_DEPENDS=	go>=1.9.4:lang/go

USES=		compiler

USE_GITHUB=	yes
GHTAG=		RELEASE.2019-06-13T01-41-13Z
COMMIT_ID=	c22439c82e5679175a99b051d10fac48cd311af0
GH_TUPLE=	${PORTNAME}:${PORTNAME}:${GHTAG}:DEFAULT/src/github.com/${PORTNAME}/${PORTNAME} \
		Azure:azure-sdk-for-go:v27.0.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:go-autorest:v11.7.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		DataDog:zstd:v1.4.0:datadog_zstd/vendor/github.com/DataDog/zstd \
		Shopify:sarama:v1.20.0:shopify_sarama/vendor/gopkg.in/Shopify/sarama.v1 \
		alecthomas:participle:v0.2.1:alecthomas_participle/vendor/github.com/alecthomas/participle \
		aliyun:aliyun-oss-go-sdk:86c17b95fcd5:aliyun_aliyun_oss_go_sdk/vendor/github.com/aliyun/aliyun-oss-go-sdk \
		apache:thrift:v0.12.0:apache_thrift/vendor/git.apache.org/thrift.git \
		bcicen:jstream:16c1f8af81c2:bcicen_jstream/vendor/github.com/bcicen/jstream \
		beorn7:perks:3a771d992973:beorn7_perks/vendor/github.com/beorn7/perks \
		census-ecosystem:opencensus-go-exporter-ocagent:v0.5.0:census_ecosystem_opencensus_go_exporter_ocagent/vendor/contrib.go.opencensus.io/exporter/ocagent \
		census-instrumentation:opencensus-go:v0.21.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		census-instrumentation:opencensus-proto:v0.2.0:census_instrumentation_opencensus_proto/vendor/github.com/census-instrumentation/opencensus-proto \
		cheggaaa:pb:v1.0.28:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		coredns:coredns:v1.4.0:coredns_coredns/vendor/github.com/coredns/coredns \
		coreos:etcd:v3.3.12:coreos_etcd/vendor/github.com/coreos/etcd \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		djherbis:atime:v1.0.0:djherbis_atime/vendor/github.com/djherbis/atime \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:20337d8c3947:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		elazarl:go-bindata-assetfs:v1.0.0:elazarl_go_bindata_assetfs/vendor/github.com/elazarl/go-bindata-assetfs \
		fatih:color:v1.7.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-sql-driver:mysql:v1.4.1:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		gogo:protobuf:v1.2.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.4.0:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:f99c8df09eb5:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:461777fb6f67:golang_net/vendor/golang.org/x/net \
		golang:oauth2:e64efc72b421:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:112230192c58:golang_sync/vendor/golang.org/x/sync \
		golang:sys:93c9922d18ae:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		golang:time:9d24e82272b4:golang_time/vendor/golang.org/x/time \
		gomodule:redigo:v2.0.0:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-genproto:5fe7a883aa19:google_go_genproto/vendor/google.golang.org/genproto \
		googleapis:gax-go:v2.0.4:googleapis_gax_go/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.4.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:v0.37.2:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:handlers:v1.4.0:gorilla_handlers/vendor/github.com/gorilla/handlers \
		gorilla:mux:v1.7.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:rpc:v1.2.0:gorilla_rpc/vendor/github.com/gorilla/rpc \
		grpc-ecosystem:grpc-gateway:v1.9.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.20.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hashicorp:errwrap:v1.0.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-multierror:v1.0.0:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-retryablehttp:v0.5.3:hashicorp_go_retryablehttp/vendor/github.com/hashicorp/go-retryablehttp \
		hashicorp:go-rootcerts:v1.0.1:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-sockaddr:v1.0.2:hashicorp_go_sockaddr/vendor/github.com/hashicorp/go-sockaddr \
		hashicorp:go-uuid:v1.0.1:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.1:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		hashicorp:vault:v1.1.0:hashicorp_vault/vendor/github.com/hashicorp/vault \
		howeyc:gopass:bf9dde6d0d2c:howeyc_gopass/vendor/github.com/howeyc/gopass \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:dc7c13fece03:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v5.3.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v5 \
		jcmturner:rpc:v0.0.2:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v0 \
		json-iterator:go:v1.1.6:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.5.0:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v1.2.1:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		klauspost:pgzip:v1.2.1:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		klauspost:readahead:v1.3.0:klauspost_readahead/vendor/github.com/klauspost/readahead \
		klauspost:reedsolomon:v1.9.1:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		lib:pq:v1.0.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:03f2033d19d5:mailru_easyjson/vendor/github.com/mailru/easyjson \
		marstr:guid:v1.1.0:marstr_guid/vendor/github.com/marstr/guid \
		mattn:go-colorable:v0.1.1:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.7:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.4:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.1.8:miekg_dns/vendor/github.com/miekg/dns \
		minio:blazer:2081f5bf0465:minio_blazer/vendor/github.com/minio/blazer \
		minio:cli:v1.20.0:minio_cli/vendor/github.com/minio/cli \
		minio:dsync:v1.0.0:minio_dsync/vendor/github.com/minio/dsync \
		minio:hdfs:v3.0.0:minio_hdfs/vendor/github.com/minio/hdfs/v3 \
		minio:highwayhash:v1.0.0:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:lsync:v0.1.0:minio_lsync/vendor/github.com/minio/lsync \
		minio:mc:f4bb0b8850cb:minio_mc/vendor/github.com/minio/mc \
		swills:minio-go:5325257a208f:swills_minio_go/vendor/github.com/swills/minio-go \
		minio:minio-go:v6.0.29:minio_minio_go/vendor/github.com/minio/minio-go/v6 \
		minio:parquet-go:9d767baf1679:minio_parquet_go/vendor/github.com/minio/parquet-go \
		minio:sha256-simd:v0.1.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		minio:sio:v0.2.0:minio_sio/vendor/github.com/minio/sio \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		nats-io:nats.go:v1.8.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.0.2:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nats-io:stan.go:v0.4.5:nats_io_stan_go/vendor/github.com/nats-io/stan.go \
		ncw:directio:v1.0.5:ncw_directio/vendor/github.com/ncw/directio \
		nsqio:go-nsq:v1.0.7:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq \
		olivere:elastic:v5.0.80:olivere_elastic/vendor/gopkg.in/olivere/elastic.v5 \
		pierrec:lz4:v2.0.5:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.3.0:pkg_profile/vendor/github.com/pkg/profile \
		prometheus:client_golang:3c4408c8b829:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:fd36f4220a90:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.2.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:bf6a532e95b1:prometheus_procfs/vendor/github.com/prometheus/procfs \
		rcrowley:go-metrics:3113b8401b8a:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:v1.6.0:rs_cors/vendor/github.com/rs/cors \
		ryanuber:go-glob:v1.0.0:ryanuber_go_glob/vendor/github.com/ryanuber/go-glob \
		satori:go.uuid:v1.2.0:satori_go_uuid/vendor/github.com/satori/go.uuid \
		segmentio:go-prompt:f0d19b6901ad:segmentio_go_prompt/vendor/github.com/segmentio/go-prompt \
		skyrings:skyring-common:d1c0bb1cbd5e:skyrings_skyring_common/vendor/github.com/skyrings/skyring-common \
		streadway:amqp:16ed540749f6:streadway_amqp/vendor/github.com/streadway/amqp \
		tidwall:gjson:v1.2.1:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.0.4:tidwall_sjson/vendor/github.com/tidwall/sjson \
		uber-go:atomic:v1.3.2:uber_go_atomic/vendor/go.uber.org/atomic \
		valyala:tcplisten:ceec8f93295a:valyala_tcplisten/vendor/github.com/valyala/tcplisten

PLIST_FILES=	bin/${PORTNAME}
USE_RC_SUBR=	minio

USERS=		minio
GROUPS=		minio

SUB_LIST=	GROUP="${GROUPS}" \
		USER="${USERS}"

do-build:
	cd ${WRKSRC}/${GH_SUBDIR} ; \
	${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} CGO_ENABLED=0 go build \
		--ldflags '-X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} -X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} -X github.com/minio/minio/cmd.CommitID=${COMMIT_ID} -X github.com/minio/minio/cmd.GOPATH=${WRKSRC} -s -w' -o ${WRKSRC}/bin/minio

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
