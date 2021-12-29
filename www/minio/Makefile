PORTNAME=	minio
PORTVERSION=	${GH_TAGNAME:S/RELEASE.//:S/Z//:S/T/-/:S/-/./g}
CATEGORIES=	www
DIST_SUBDIR=	minio

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Amazon S3 compatible object storage server

LICENSE=	APACHE20

USES=		compiler cpe go:modules

USE_GITHUB=	yes
GHTAG=		RELEASE.2021-12-27T07-23-18Z
COMMIT_ID=	bb97eafa82544de7d78e8b614fe13f9754f58d6c

GH_TUPLE=	${PORTNAME}:${PORTNAME}:${GHTAG}:DEFAULT \
		Azure:azure-pipeline-go:v0.2.2:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-blob-go:v0.10.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:go-ntlmssp:66371956d46c:azure_go_ntlmssp/vendor/github.com/Azure/go-ntlmssp \
		PuerkitoBio:purell:v1.1.1:puerkitobio_purell/vendor/github.com/PuerkitoBio/purell \
		PuerkitoBio:urlesc:de5bf2ad4578:puerkitobio_urlesc/vendor/github.com/PuerkitoBio/urlesc \
		Shopify:sarama:v1.27.2:shopify_sarama/vendor/github.com/Shopify/sarama \
		StackExchange:wmi:v1.2.1:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		VividCortex:ewma:v1.1.1:vividcortex_ewma/vendor/github.com/VividCortex/ewma \
		alecthomas:participle:v0.2.1:alecthomas_participle/vendor/github.com/alecthomas/participle \
		apache:thrift:v0.15.0:apache_thrift/vendor/github.com/apache/thrift \
		asaskevich:govalidator:7a23bdc65eef:asaskevich_govalidator/vendor/github.com/asaskevich/govalidator \
		bcicen:jstream:v1.0.1:bcicen_jstream/vendor/github.com/bcicen/jstream \
		beevik:ntp:v0.3.0:beevik_ntp/vendor/github.com/beevik/ntp \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bits-and-blooms:bitset:v1.2.0:bits_and_blooms_bitset/vendor/github.com/bits-and-blooms/bitset \
		bits-and-blooms:bloom:v3.0.1:bits_and_blooms_bloom_v3/vendor/github.com/bits-and-blooms/bloom/v3 \
		briandowns:spinner:v1.16.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		buger:jsonparser:v1.1.1:buger_jsonparser/vendor/github.com/buger/jsonparser \
		census-instrumentation:opencensus-go:v0.23.0:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.2:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cheggaaa:pb:v1.0.29:cheggaaa_pb/vendor/github.com/cheggaaa/pb \
		colinmarc:hdfs:v2.2.0:colinmarc_hdfs_v2/vendor/github.com/colinmarc/hdfs/v2 \
		coredns:coredns:v1.4.0:coredns_coredns/vendor/github.com/coredns/coredns \
		coreos:go-oidc:v2.1.0:coreos_go_oidc/vendor/github.com/coreos/go-oidc \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		coreos:go-systemd:v22.3.2:coreos_go_systemd_v22/vendor/github.com/coreos/go-systemd/v22 \
		cosnicolaou:pbzip2:v1.0.1:cosnicolaou_pbzip2/vendor/github.com/cosnicolaou/pbzip2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dchest:siphash:v1.2.1:dchest_siphash/vendor/github.com/dchest/siphash \
		djherbis:atime:v1.0.0:djherbis_atime/vendor/github.com/djherbis/atime \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dswarbrick:smart:909a45200d6d:dswarbrick_smart/vendor/github.com/dswarbrick/smart \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:v1.3.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		elastic:go-elasticsearch:v7.12.0:elastic_go_elasticsearch_v7/vendor/github.com/elastic/go-elasticsearch/v7 \
		emicklei:go-restful:v2.9.5:emicklei_go_restful/vendor/github.com/emicklei/go-restful \
		etcd-io:etcd:v3.5.0:etcd_io_etcd/vendor/go.etcd.io/etcd/ \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fatih:structs:v1.1.0:fatih_structs/vendor/github.com/fatih/structs \
		georgysavva:scany:v0.2.7:georgysavva_scany/vendor/github.com/georgysavva/scany \
		go-asn1-ber:asn1-ber:v1.5.1:go_asn1_ber_asn1_ber/vendor/github.com/go-asn1-ber/asn1-ber \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.63.2:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.2.4:go_ldap_ldap_v3/vendor/github.com/go-ldap/ldap \
		go-logr:logr:v0.4.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-ole:go-ole:v1.2.6:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-openapi:analysis:v0.20.0:go_openapi_analysis/vendor/github.com/go-openapi/analysis \
		go-openapi:errors:v0.19.9:go_openapi_errors/vendor/github.com/go-openapi/errors \
		go-openapi:jsonpointer:v0.19.5:go_openapi_jsonpointer/vendor/github.com/go-openapi/jsonpointer \
		go-openapi:jsonreference:v0.19.5:go_openapi_jsonreference/vendor/github.com/go-openapi/jsonreference \
		go-openapi:loads:v0.20.2:go_openapi_loads/vendor/github.com/go-openapi/loads \
		go-openapi:runtime:v0.19.24:go_openapi_runtime/vendor/github.com/go-openapi/runtime \
		go-openapi:spec:v0.20.3:go_openapi_spec/vendor/github.com/go-openapi/spec \
		go-openapi:strfmt:v0.20.0:go_openapi_strfmt/vendor/github.com/go-openapi/strfmt \
		go-openapi:swag:v0.19.14:go_openapi_swag/vendor/github.com/go-openapi/swag \
		go-openapi:validate:v0.20.2:go_openapi_validate/vendor/github.com/go-openapi/validate \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-yaml:yaml:496545a6307b:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goccy:go-json:v0.7.9:goccy_go_json/vendor/github.com/goccy/go-json \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-jwt:jwt:v3.2.2:golang_jwt_jwt/vendor/github.com/golang-jwt/jwt \
		golang-jwt:jwt:v4.1.0:golang_jwt_jwt_v4/vendor/github.com/golang-jwt/jwt/v4 \
		golang:appengine:v1.6.7:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:4570a0811e8b:golang_crypto/vendor/golang.org/x/crypto \
		golang:glog:23def4e6c14b:golang_glog/vendor/github.com/golang/glog \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:net:69e39bad7dc2:golang_net/vendor/golang.org/x/net \
		golang:oauth2:2bc19b11175f:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.3:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:036812b2e83c:golang_sync/vendor/golang.org/x/sync \
		golang:sys:9d6173849985:golang_sys/vendor/golang.org/x/sys \
		golang:term:03fcf44c2211:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:1f47c861a9ac:golang_time/vendor/golang.org/x/time \
		gomodule:redigo:v1.8.5:gomodule_redigo/vendor/github.com/gomodule/redigo \
		google:go-cmp:v0.5.6:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:c7af6a1a74c9:google_go_genproto/vendor/google.golang.org/genproto \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:uuid:v1.3.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.1.1:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.5.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.58.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:storage/v1.10.0:googleapis_google_cloud_go_storage \
		googleapis:google-cloud-go:v0.94.1:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		grpc:grpc-go:v1.41.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		h2non:filetype:v1.0.5:h2non_filetype/vendor/gopkg.in/h2non/filetype.v1 \
		hashicorp:errwrap:v1.1.0:hashicorp_errwrap/vendor/github.com/hashicorp/errwrap \
		hashicorp:go-multierror:v1.1.1:hashicorp_go_multierror/vendor/github.com/hashicorp/go-multierror \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:aescts:v2.0.0:jcmturner_aescts_v2/vendor/github.com/jcmturner/aescts \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:dnsutils:v2.0.0:jcmturner_dnsutils_v2/vendor/github.com/jcmturner/dnsutils \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:goidentity:v6.0.1:jcmturner_goidentity_v6/vendor/github.com/jcmturner/goidentity \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:gokrb5:v8.4.2:jcmturner_gokrb5_v8/vendor/github.com/jcmturner/gokrb5 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jcmturner:rpc:v2.0.3:jcmturner_rpc_v2/vendor/github.com/jcmturner/rpc \
		jessevdk:go-flags:v1.4.0:jessevdk_go_flags/vendor/github.com/jessevdk/go-flags \
		josharian:intern:v1.0.0:josharian_intern/vendor/github.com/josharian/intern \
		json-iterator:go:v1.1.12:json_iterator_go/vendor/github.com/json-iterator/go \
		klauspost:compress:v1.13.6:klauspost_compress/vendor/github.com/klauspost/compress \
		klauspost:cpuid:v2.0.9:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		klauspost:pgzip:v1.2.5:klauspost_pgzip/vendor/github.com/klauspost/pgzip \
		klauspost:readahead:v1.3.1:klauspost_readahead/vendor/github.com/klauspost/readahead \
		klauspost:reedsolomon:v1.9.15:klauspost_reedsolomon/vendor/github.com/klauspost/reedsolomon \
		kubernetes-sigs:controller-runtime:v0.8.0:kubernetes_sigs_controller_runtime/vendor/sigs.k8s.io/controller-runtime \
		kubernetes-sigs:structured-merge-diff:v4.1.0:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.21.1:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.21.1:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.21.1:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.8.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:kube-openapi:591a79e4bda7:kubernetes_kube_openapi/vendor/k8s.io/kube-openapi \
		kubernetes:utils:67b214c5f920:kubernetes_utils/vendor/k8s.io/utils \
		lestrrat-go:backoff:v2.0.8:lestrrat_go_backoff_v2/vendor/github.com/lestrrat-go/backoff/v2 \
		lestrrat-go:blackmagic:v1.0.0:lestrrat_go_blackmagic/vendor/github.com/lestrrat-go/blackmagic \
		lestrrat-go:httpcc:v1.0.0:lestrrat_go_httpcc/vendor/github.com/lestrrat-go/httpcc \
		lestrrat-go:iter:v1.0.1:lestrrat_go_iter/vendor/github.com/lestrrat-go/iter \
		lestrrat-go:jwx:v1.2.7:lestrrat_go_jwx/vendor/github.com/lestrrat-go/jwx \
		lestrrat-go:option:v1.0.0:lestrrat_go_option/vendor/github.com/lestrrat-go/option \
		lib:pq:v1.9.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:v0.7.6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.10:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mb0:glob:1eb79d2de6c4:mb0_glob/vendor/github.com/mb0/glob \
		miekg:dns:v1.1.43:miekg_dns/vendor/github.com/miekg/dns \
		minio:argon2:v1.0.0:minio_argon2/vendor/github.com/minio/argon2 \
		minio:cli:v1.22.0:minio_cli/vendor/github.com/minio/cli \
		minio:colorjson:v1.0.1:minio_colorjson/vendor/github.com/minio/colorjson \
		minio:console:v0.13.1:minio_console/vendor/github.com/minio/console \
		minio:csvparser:v1.0.0:minio_csvparser/vendor/github.com/minio/csvparser \
		minio:direct-csi:f7776f7961bf:minio_direct_csi/vendor/github.com/minio/direct-csi \
		minio:filepath:v1.0.0:minio_filepath/vendor/github.com/minio/filepath \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		minio:kes:v0.14.0:minio_kes/vendor/github.com/minio/kes \
		minio:madmin-go:v1.1.23:minio_madmin_go/vendor/github.com/minio/madmin-go \
		minio:mc:23a05f5a17f2:minio_mc/vendor/github.com/minio/mc \
		minio:md5-simd:v1.1.2:minio_md5_simd/vendor/github.com/minio/md5-simd \
		minio:minio-go:v7.0.20:minio_minio_go_v7/vendor/github.com/minio/minio-go/v7 \
		minio:operator:31460bbbc4b7:minio_operator/vendor/github.com/minio/operator \
		minio:parquet-go:v1.1.0:minio_parquet_go/vendor/github.com/minio/parquet-go \
		minio:pkg:v1.1.11:minio_pkg/vendor/github.com/minio/pkg \
		minio:selfupdate:v0.4.0:minio_selfupdate/vendor/github.com/minio/selfupdate \
		minio:sha256-simd:v1.0.0:minio_sha256_simd/vendor/github.com/minio/sha256-simd \
		minio:simdjson-go:v0.2.1:minio_simdjson_go/vendor/github.com/minio/simdjson-go \
		minio:sio:v0.3.0:minio_sio/vendor/github.com/minio/sio \
		minio:zipindex:v0.2.1:minio_zipindex/vendor/github.com/minio/zipindex \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.4.1:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.2:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		mongodb:mongo-go-driver:v1.4.6:mongodb_mongo_go_driver/vendor/go.mongodb.org/mongo-driver \
		montanaflynn:stats:v0.6.6:montanaflynn_stats/vendor/github.com/montanaflynn/stats \
		nats-io:jwt:v2.0.2:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.3.2:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats-streaming-server:v0.21.2:nats_io_nats_streaming_server/vendor/github.com/nats-io/nats-streaming-server \
		nats-io:nats.go:4b75fc59ae30:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.3.0:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		nats-io:stan.go:v0.8.3:nats_io_stan_go/vendor/github.com/nats-io/stan.go \
		ncw:directio:v1.0.5:ncw_directio/vendor/github.com/ncw/directio \
		nsqio:go-nsq:v1.0.8:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq \
		philhofer:fwd:5c56ac6d0bb9:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.6.0:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pkg:profile:v1.6.0:pkg_profile/vendor/github.com/pkg/profile \
		pkg:xattr:v0.4.3:pkg_xattr/vendor/github.com/pkg/xattr \
		pmezard:go-difflib:5d4384ee4fb2:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		posener:complete:v1.2.3:posener_complete/vendor/github.com/posener/complete \
		pquerna:cachecontrol:0dec1b30a021:pquerna_cachecontrol/vendor/github.com/pquerna/cachecontrol \
		prometheus:client_golang:v1.11.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.31.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.7.3:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.27.1:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		rjeczalik:notify:v0.9.2:rjeczalik_notify/vendor/github.com/rjeczalik/notify \
		rs:cors:v1.7.0:rs_cors/vendor/github.com/rs/cors \
		rs:dnscache:295bba877686:rs_dnscache/vendor/github.com/rs/dnscache \
		rs:xid:v1.3.0:rs_xid/vendor/github.com/rs/xid \
		secure-io:sio-go:v0.3.1:secure_io_sio_go/vendor/github.com/secure-io/sio-go \
		shirou:gopsutil:v3.21.9:shirou_gopsutil_v3/vendor/github.com/shirou/gopsutil \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		streadway:amqp:v1.0.0:streadway_amqp/vendor/github.com/streadway/amqp \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tidwall:gjson:v1.11.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:sjson:v1.2.3:tidwall_sjson/vendor/github.com/tidwall/sjson \
		tinylib:msgp:e818a1881b0e:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.9:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.3.0:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.7.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.19.1:uber_go_zap/vendor/go.uber.org/zap \
		unrolled:secure:v1.0.9:unrolled_secure/vendor/github.com/unrolled/secure \
		valyala:bytebufferpool:v1.0.0:valyala_bytebufferpool/vendor/github.com/valyala/bytebufferpool \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep \
		yargevad:filepathx:v1.0.0:yargevad_filepathx/vendor/github.com/yargevad/filepathx \
		zeebo:xxh3:v1.0.0:zeebo_xxh3/vendor/github.com/zeebo/xxh3 \
		swills:duration:faac084b6075:swills_duration/vendor/maze.io/x/duration

                # Errors found during processing:
                #       tag v4.0.0 doesn't seem to exist in decred/dcrd

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_storage}/storage ${WRKSRC}/vendor/cloud.google.com/go/storage
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io/etcd/api
	@${RLN} ${WRKSRC}/vendor/go.etcd.io/etcd/etcd-3.5.0/api ${WRKSRC}/vendor/go.etcd.io/etcd/api/v3
	@${MKDIR} ${WRKSRC}/vendor/go.etcd.io/etcd/client/pkg
	@${RLN} ${WRKSRC}/vendor/go.etcd.io/etcd/etcd-3.5.0/client/v3 ${WRKSRC}/vendor/go.etcd.io/etcd/client/v3
	@${RLN} ${WRKSRC}/vendor/go.etcd.io/etcd/etcd-3.5.0/client/pkg ${WRKSRC}/vendor/go.etcd.io/etcd/client/pkg/v3

GO_BUILDFLAGS=	-ldflags=' \
		-X github.com/minio/minio/cmd.Version=${GH_TAGNAME:C/RELEASE\.//:C|(..)-(..)-(..)Z|\1:\2:\3Z|} \
		-X github.com/minio/minio/cmd.ReleaseTag=${GH_TAGNAME} \
		-X github.com/minio/minio/cmd.CommitID=${COMMIT_ID} \
		-X github.com/minio/minio/cmd.ShortCommitID=${COMMIT_ID:C|(............).*|\1|} \
		-X github.com/minio/minio/cmd.GOPATH=${WRKSRC} -s -w'

PLIST_FILES=	bin/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

MINIO_USER?=	${PORTNAME}
MINIO_GROUP?=	${PORTNAME}
MINIO_DBDIR?=	/var/db/${PORTNAME}

USERS=		${MINIO_USER}
GROUPS=		${MINIO_GROUP}

SUB_LIST=	DBDIR=${MINIO_DBDIR} \
		GROUP="${GROUPS}" \
		USER="${USERS}"

.include <bsd.port.mk>
