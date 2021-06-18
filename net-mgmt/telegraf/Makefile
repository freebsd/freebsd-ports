# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>

PORTNAME=	telegraf
DISTVERSIONPREFIX=v
DISTVERSION=	1.19.0
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

ONLY_FOR_ARCHS=	aarch64 amd64 armv6 armv7 i386

USES=		go:modules

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GO_BUILDFLAGS=	-ldflags "-X main.goos=freebsd -X main.goarch=${ARCH} -X main.version=${DISTVERSION}"
GO_TARGET=	./cmd/telegraf

SUB_FILES=	telegraf
SUB_LIST=	TELEGRAF_USER=${TELEGRAF_USER} \
		TELEGRAF_GROUP=${TELEGRAF_GROUP} \
		TELEGRAF_LOGDIR=${TELEGRAF_LOGDIR}
PLIST_SUB=	TELEGRAF_USER=${TELEGRAF_USER} \
		TELEGRAF_GROUP=${TELEGRAF_GROUP} \
		TELEGRAF_LOGDIR=${TELEGRAF_LOGDIR}

TELEGRAF_USER=	telegraf
TELEGRAF_GROUP=	telegraf

USERS=		${TELEGRAF_USER}
GROUPS=		${TELEGRAF_GROUP}

TELEGRAF_LOGDIR=/var/log/${PORTNAME}

GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}
# run make gomod-vendor, and manually manage these lines:
# moby (reset to moby/moby using version hash), rethinkdb, WireGuard (both)
# aws has weird sub dependencies that need to be manually crafted

GH_TUPLE=	\
		Azure:azure-amqp-common-go:v3.0.0:azure_azure_amqp_common_go_v3/vendor/github.com/Azure/azure-amqp-common-go/v3 \
		Azure:azure-event-hubs-go:v3.2.0:azure_azure_event_hubs_go_v3/vendor/github.com/Azure/azure-event-hubs-go/v3 \
		Azure:azure-pipeline-go:v0.2.3:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:v45.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-storage-blob-go:v0.13.0:azure_azure_storage_blob_go/vendor/github.com/Azure/azure-storage-blob-go \
		Azure:azure-storage-queue-go:6ed74e755687:azure_azure_storage_queue_go/vendor/github.com/Azure/azure-storage-queue-go \
		Azure:go-amqp:v0.12.6:azure_go_amqp/vendor/github.com/Azure/go-amqp \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:55c0c4ebc34d:azure_go_autorest_cli \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_to \
		Azure:go-autorest:9ff0227e2e0b:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.11.17:azure_go_autorest_autorest \
		Azure:go-autorest:b3a0b30a7423:azure_go_autorest_date \
		Azure:go-autorest:c0fe8b0fea3d:azure_go_autorest_auth \
		Azure:go-autorest:logger/v0.2.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.6.0:azure_go_autorest_tracing \
		Azure:go-autorest:v14.2.0:azure_go_autorest/vendor/github.com/Azure/go-autorest \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Mellanox:rdmamap:7c3c4763a6ee:mellanox_rdmamap/vendor/github.com/Mellanox/rdmamap \
		Microsoft:go-winio:6eac466e5fa3:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Microsoft:hcsshim:v0.8.16:microsoft_hcsshim/vendor/github.com/Microsoft/hcsshim \
		Shopify:sarama:v1.27.2:shopify_sarama/vendor/github.com/Shopify/sarama \
		StackExchange:wmi:fe8f1750fd46:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		aerospike:aerospike-client-go:v1.27.0:aerospike_aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		alecthomas:units:f65c72e2690d:alecthomas_units/vendor/github.com/alecthomas/units \
		aliyun:alibaba-cloud-sdk-go:v1.61.1004:aliyun_alibaba_cloud_sdk_go/vendor/github.com/aliyun/alibaba-cloud-sdk-go \
		amir:raidman:1ccc43bfb9c9:amir_raidman/vendor/github.com/amir/raidman \
		antchfx:xmlquery:v1.3.5:antchfx_xmlquery/vendor/github.com/antchfx/xmlquery \
		antchfx:xpath:v1.1.11:antchfx_xpath/vendor/github.com/antchfx/xpath \
		apache:arrow:b2287a20f230:apache_arrow_arrow/vendor/github.com/apache/arrow \
		apache:thrift:v0.13.0:apache_thrift/vendor/github.com/apache/thrift \
		aristanetworks:glog:67e8567f59f3:aristanetworks_glog/vendor/github.com/aristanetworks/glog \
		aristanetworks:goarista:a123909ec740:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		armon:go-metrics:v0.3.3:armon_go_metrics/vendor/github.com/armon/go-metrics \
		aws:aws-sdk-go-v2:credentials/v1.1.5:aws_aws_sdk_go_v2_credentials \
		aws:aws-sdk-go-v2:fdbaadbce5fd:aws_aws_sdk_go_v2_config \
		aws:aws-sdk-go-v2:service/internal/s3shared/v1.2.2:aws_aws_sdk_go_v2_s3shared \
		aws:aws-sdk-go-v2:v1.1.0:aws_aws_sdk_go_v2_ec2 \
		aws:aws-sdk-go-v2:v1.3.2:aws_aws_sdk_go_v2/vendor/github.com/aws/aws-sdk-go-v2 \
		aws:aws-sdk-go-v2:v1.5.0:aws_aws_sdk_go_v2_s3 \
		aws:aws-sdk-go:v1.34.34:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		aws:smithy-go:v1.3.1:aws_smithy_go/vendor/github.com/aws/smithy-go \
		benbjohnson:clock:v1.0.3:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-hostpool:v0.1.0:bitly_go_hostpool/vendor/github.com/bitly/go-hostpool \
		bmatcuk:doublestar:v3.0.0:bmatcuk_doublestar_v3/vendor/github.com/bmatcuk/doublestar/v3 \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		caio:go-tdigest:v3.1.0:caio_go_tdigest/vendor/github.com/caio/go-tdigest \
		cenkalti:backoff:v2.2.1:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cisco-ie:nx-telemetry-proto:82441e232cf6:cisco_ie_nx_telemetry_proto/vendor/github.com/cisco-ie/nx-telemetry-proto \
		cloudfoundry:clock:v1.0.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		collectd:go-collectd:v0.5.0:collectd_go_collectd/vendor/collectd.org \
		containerd:cgroups:8a68de567b68:containerd_cgroups/vendor/github.com/containerd/cgroups \
		containerd:containerd:v1.5.0-beta.4:containerd_containerd/vendor/github.com/containerd/containerd \
		coreos:etcd:v3.3.22:coreos_etcd/vendor/github.com/coreos/etcd \
		coreos:go-semver:v0.3.0:coreos_go_semver/vendor/github.com/coreos/go-semver \
		couchbase:go-couchbase:16db1f1fe037:couchbase_go_couchbase/vendor/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:0da75df14530:couchbase_gomemcached/vendor/github.com/couchbase/gomemcached \
		couchbase:goutils:e865a1461c8a:couchbase_goutils/vendor/github.com/couchbase/goutils \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:v0.10.0:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		devigned:tab:v0.1.1:devigned_tab/vendor/github.com/devigned/tab \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgrijalva:jwt-go:v4.0.0-preview1:dgrijalva_jwt_go_v4/vendor/github.com/dgrijalva/jwt-go/v4 \
		dimchansky:utfbom:v1.1.1:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		djherbis:times:v1.2.0:djherbis_times/vendor/gopkg.in/djherbis/times.v1 \
		docker:distribution:v2.7.1:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.4.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.4.0:docker_go_units/vendor/github.com/docker/go-units \
		dominikh:go-tools:v0.0.1-2020.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		dynatrace-oss:dynatrace-metric-utils-go:v0.1.0:dynatrace_oss_dynatrace_metric_utils_go/vendor/github.com/dynatrace-oss/dynatrace-metric-utils-go \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		echlebek:timeproxy:v1.0.0:echlebek_timeproxy/vendor/github.com/echlebek/timeproxy \
		eclipse:paho.mqtt.golang:v1.3.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		fatih:color:v1.9.0:fatih_color/vendor/github.com/fatih/color \
		fatih:pool:v2.0.0:fatih_pool/vendor/gopkg.in/fatih/pool.v2 \
		form3tech-oss:jwt-go:v3.2.2:form3tech_oss_jwt_go/vendor/github.com/form3tech-oss/jwt-go \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ini:ini:v1.42.0:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-ldap:ldap:v3.1.0:go_ldap_ldap/vendor/gopkg.in/ldap.v3 \
		go-logfmt:logfmt:v0.5.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-logr:logr:v0.2.0:go_logr_logr/vendor/github.com/go-logr/logr \
		go-mgo:mgo:a6b53ec6cb22:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:v1.2.4:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-ping:ping:52eed920f98c:go_ping_ping/vendor/github.com/go-ping/ping \
		go-redis:redis:v6.15.9:go_redis_redis/vendor/github.com/go-redis/redis \
		go-sourcemap:sourcemap:v1.0.5:go_sourcemap_sourcemap/vendor/gopkg.in/sourcemap.v1 \
		go-sql-driver:mysql:v1.6.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-stack:stack:v1.8.0:go_stack_stack/vendor/github.com/go-stack/stack \
		go-tomb:tomb:d5d1b5820637:go_tomb_tomb_1/vendor/gopkg.in/tomb.v2 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goburrow:modbus:v0.1.0:goburrow_modbus/vendor/github.com/goburrow/modbus \
		goburrow:serial:v0.1.0:goburrow_serial/vendor/github.com/goburrow/serial \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:uuid:v3.2.0:gofrs_uuid_1/vendor/github.com/satori/go.uuid \
		gofrs:uuid:v3.3.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:googleapis:v1.4.0:gogo_googleapis/vendor/github.com/gogo/googleapis \
		gogo:protobuf:v1.3.2:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang-sql:civil:cb61b32ac6fe:golang_sql_civil/vendor/github.com/golang-sql/civil \
		golang:appengine:v1.6.6:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:c07d793c2f9a:golang_crypto/vendor/golang.org/x/crypto \
		golang:geo:5b978397cfec:golang_geo/vendor/github.com/golang/geo \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.3.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:e18ecbb05110:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.1:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:09787c993a3a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:47abb6519492:golang_sys/vendor/golang.org/x/sys \
		golang:term:7de9c90e9dd1:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.4:golang_text/vendor/golang.org/x/text \
		golang:time:3af7569d3a1e:golang_time/vendor/golang.org/x/time \
		golang:tools:v0.1.0:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:flatbuffers:v1.11.0:google_flatbuffers/vendor/github.com/google/flatbuffers \
		google:go-cmp:v0.5.5:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:8816d57aaa9a:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v32.1.0:google_go_github_v32/vendor/github.com/google/go-github/v32 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:gofuzz:v1.1.0:google_gofuzz/vendor/github.com/google/gofuzz \
		google:starlark-go:7a1108eaa012:google_starlark_go/vendor/go.starlark.net \
		google:uuid:v1.2.0:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:gnostic:v0.4.1:googleapis_gnostic/vendor/github.com/googleapis/gnostic \
		googleapis:google-api-go-client:v0.29.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:bigquery/v1.4.0:googleapis_google_cloud_go_bigquery \
		googleapis:google-cloud-go:pubsub/v1.2.0:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:v0.56.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gopcua:opcua:v0.1.13:gopcua_opcua/vendor/github.com/gopcua/opcua \
		rethinkdb:rethinkdb-go:v3.0.5:gorethink_gorethink/vendor/gopkg.in/gorethink/gorethink.v3 \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.4.2:gorilla_websocket/vendor/github.com/gorilla/websocket \
		gosnmp:gosnmp:v1.32.0:gosnmp_gosnmp/vendor/github.com/gosnmp/gosnmp \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		grid-x:modbus:c4a3d042e99b:grid_x_modbus/vendor/github.com/grid-x/modbus \
		grid-x:serial:e24bc9bf6f08:grid_x_serial/vendor/github.com/grid-x/serial \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.37.0:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		harlow:kinesis-consumer:2f58b136fee0:harlow_kinesis_consumer/vendor/github.com/harlow/kinesis-consumer \
		hashicorp:consul:v1.8.1:hashicorp_consul_api/vendor/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:v0.5.1:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-hclog:v0.12.2:hashicorp_go_hclog/vendor/github.com/hashicorp/go-hclog \
		hashicorp:go-immutable-radix:v1.2.0:hashicorp_go_immutable_radix/vendor/github.com/hashicorp/go-immutable-radix \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-rootcerts:v1.0.2:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:golang-lru:v0.5.4:hashicorp_golang_lru/vendor/github.com/hashicorp/golang-lru \
		hashicorp:serf:v0.9.5:hashicorp_serf/vendor/github.com/hashicorp/serf \
		influxdata:apcupsd:694d5caead0e:influxdata_apcupsd/vendor/github.com/mdlayher/apcupsd \
		influxdata:go-syslog:v2.0.1:influxdata_go_syslog_v2/vendor/github.com/influxdata/go-syslog/v2 \
		influxdata:influxdb-observability:86ae73cafd31:influxdata_influxdb_observability_common/vendor/github.com/influxdata/influxdb-observability \
		influxdata:tail:03a791b270e4:influxdata_tail/vendor/github.com/influxdata/tail \
		influxdata:toml:270119a8ce65:influxdata_toml/vendor/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a71ef8:influxdata_wlog/vendor/github.com/influxdata/wlog \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.5.0:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.1:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:3430c5407db8:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.3.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.6.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jaegertracing:jaeger:v1.15.1:jaegertracing_jaeger/vendor/github.com/jaegertracing/jaeger \
		james4k:rcon:8fbb8268b60a:james4k_rcon/vendor/github.com/james4k/rcon \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jpillora:backoff:v1.0.0:jpillora_backoff/vendor/github.com/jpillora/backoff \
		json-iterator:go:v1.1.10:json_iterator_go/vendor/github.com/json-iterator/go \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:service:v1.0.0:kardianos_service/vendor/github.com/kardianos/service \
		karrick:godirwalk:v1.16.1:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.11.3:klauspost_compress/vendor/github.com/klauspost/compress \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes-sigs:structured-merge-diff:v4.0.2:kubernetes_sigs_structured_merge_diff/vendor/sigs.k8s.io/structured-merge-diff/v4 \
		kubernetes-sigs:yaml:v1.2.0:kubernetes_sigs_yaml/vendor/sigs.k8s.io/yaml \
		kubernetes:api:v0.20.4:kubernetes_api/vendor/k8s.io/api \
		kubernetes:apimachinery:v0.20.4:kubernetes_apimachinery/vendor/k8s.io/apimachinery \
		kubernetes:client-go:v0.20.4:kubernetes_client_go/vendor/k8s.io/client-go \
		kubernetes:klog:v2.4.0:kubernetes_klog/vendor/k8s.io/klog/v2 \
		kubernetes:utils:67b214c5f920:kubernetes_utils/vendor/k8s.io/utils \
		leodido:ragel-machinery:299bdde78165:leodido_ragel_machinery/vendor/github.com/leodido/ragel-machinery \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:v0.7.1:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-colorable:v0.1.6:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-ieproxy:v0.0.1:mattn_go_ieproxy/vendor/github.com/mattn/go-ieproxy \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:c182affec369:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mdlayher:genetlink:v1.0.0:mdlayher_genetlink/vendor/github.com/mdlayher/genetlink \
		mdlayher:netlink:v1.1.0:mdlayher_netlink/vendor/github.com/mdlayher/netlink \
		microsoft:ApplicationInsights-Go:v0.4.4:microsoft_applicationinsights_go/vendor/github.com/microsoft/ApplicationInsights-Go \
		miekg:dns:v1.1.31:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:v1.2.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:ipvs:v1.0.1:moby_ipvs/vendor/github.com/moby/ipvs \
		moby:moby:v20.10.6:moby_moby/vendor/github.com/docker/docker \
		moby:sys:mount/v0.2.0:moby_sys_mount/vendor/github.com/moby/sys \
		moby:sys:mountinfo/v0.4.1:moby_sys_mountinfo \
		moby:term:df9cb8a40635:moby_term/vendor/github.com/moby/term \
		modern-go:concurrent:bacd9c7ef1dd:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		multiplay:go-ts3:v1.0.0:multiplay_go_ts3/vendor/github.com/multiplay/go-ts3 \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		nats-io:jwt:v0.3.2:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.1.4:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.10.0:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.1.4:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		newrelic:newrelic-telemetry-sdk-go:v0.5.1:newrelic_newrelic_telemetry_sdk_go/vendor/github.com/newrelic/newrelic-telemetry-sdk-go \
		nsqio:go-nsq:v1.0.8:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq \
		olivere:elastic:v5.0.70:olivere_elastic/vendor/gopkg.in/olivere/elastic.v5 \
		openconfig:gnmi:33a1865c3029:openconfig_gnmi/vendor/github.com/openconfig/gnmi \
		opencontainers:go-digest:v1.0.0:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opencontainers:runc:v1.0.0-rc93:opencontainers_runc/vendor/github.com/opencontainers/runc \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.2.0:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:openzipkin_zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing \
		philhofer:fwd:v1.1.1:philhofer_fwd/vendor/github.com/philhofer/fwd \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:browser:0a3d74bf9ce4:pkg_browser/vendor/github.com/pkg/browser \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.7.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.15.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:e83ef207b6c2:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		remyoudompheng:bigfft:eec4a21b6bb0:remyoudompheng_bigfft/vendor/github.com/remyoudompheng/bigfft \
		riemann:riemann-go-client:v0.5.0:riemann_riemann_go_client/vendor/github.com/riemann/riemann-go-client \
		robertkrimen:otto:c382bd3c16ff:robertkrimen_otto/vendor/github.com/robertkrimen/otto \
		robfig:cron:v3.0.1:robfig_cron_v3/vendor/github.com/robfig/cron/v3 \
		safchain:ethtool:f459e2d13664:safchain_ethtool/vendor/github.com/safchain/ethtool \
		samuel:go-zookeeper:2164a8ac840e:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		shirou:gopsutil:v3.21.3:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:408a2507e114:shopspring_decimal/vendor/github.com/shopspring/decimal \
		signalfx:com_signalfx_metrics_protobuf:1fb69526e884:signalfx_com_signalfx_metrics_protobuf/vendor/github.com/signalfx/com_signalfx_metrics_protobuf \
		signalfx:gohistogram:1ccfd2ff5083:signalfx_gohistogram/vendor/github.com/signalfx/gohistogram \
		signalfx:golib:v3.3.0:signalfx_golib_v3/vendor/github.com/signalfx/golib/v3 \
		signalfx:sapm-proto:v0.4.0:signalfx_sapm_proto/vendor/github.com/signalfx/sapm-proto \
		sirupsen:logrus:v1.7.0:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		snowflakedb:gosnowflake:v1.5.0:snowflakedb_gosnowflake/vendor/github.com/snowflakedb/gosnowflake \
		streadway:amqp:edfb9018d271:streadway_amqp/vendor/github.com/streadway/amqp \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tbrandon:mbserver:993e1772cc62:tbrandon_mbserver/vendor/github.com/tbrandon/mbserver \
		testcontainers:testcontainers-go:v0.11.0:testcontainers_testcontainers_go/vendor/github.com/testcontainers/testcontainers-go \
		tidwall:gjson:v1.6.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tinylib:msgp:v1.1.5:tinylib_msgp/vendor/github.com/tinylib/msgp \
		tklauser:go-sysconf:v0.3.5:tklauser_go_sysconf/vendor/github.com/tklauser/go-sysconf \
		tklauser:numcpus:v0.2.2:tklauser_numcpus/vendor/github.com/tklauser/numcpus \
		uber-go:atomic:v1.7.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.6.0:uber_go_multierr/vendor/go.uber.org/multierr \
		vapourismo:knx-go:75fe09ace330:vapourismo_knx_go/vendor/github.com/vapourismo/knx-go \
		vishvananda:netlink:v1.1.0:vishvananda_netlink \
		vishvananda:netns:0a2b9b5464df:vishvananda_netns/vendor/github.com/vishvananda/netns \
		vjeantet:grok:v1.0.1:vjeantet_grok/vendor/github.com/vjeantet/grok \
		vmware:govmomi:v0.19.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		wavefronthq:wavefront-sdk-go:v0.9.7:wavefronthq_wavefront_sdk_go/vendor/github.com/wavefronthq/wavefront-sdk-go \
		WireGuard:wireguard-go:v0.0.20200121:WireGuard_wireguard_go/vendor/golang.zx2c4.com/wireguard \
		WireGuard:wgctrl-go:e35592f146e4:WireGuard_wgctrl_go/vendor/golang.zx2c4.com/wireguard/wgctrl \
		wvanbergen:kafka:e2edea948ddf:wvanbergen_kafka/vendor/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:f72d8611297a:wvanbergen_kazoo_go/vendor/github.com/wvanbergen/kazoo-go \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep \
		yuin:gopher-lua:46796da1b0b4:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

GL_TUPLE=	\
		cznic:cc:276fcd8507b301b88f3c40ef8ac7a3ebfbb0d04c:cznic_cc/vendor/modernc.org/cc/v3 \
		cznic:ccgo:b1994ccffcb55b4b61537b41488b95ff0eced811:cznic_ccgo/vendor/modernc.org/ccgo/v3 \
		cznic:libc:0f6da017916bb160e9190cab21d7cb6b99cef6aa:cznic_libc/vendor/modernc.org/libc \
		cznic:mathutil:19b10d78032b3c42e8b92557729019b39392a1f6:cznic_mathutil/vendor/modernc.org/mathutil \
		cznic:memory:a54fc7a24ad7e54b9d97ed79970790befcf3d088:cznic_memory/vendor/modernc.org/memory \
		cznic:opt:e7b6288dd9a69c9c36a10a93d0bd007ba3dcb30f:cznic_opt/vendor/modernc.org/opt \
		cznic:sqlite:0b2367747cba5699fd291b6364ebf2f7c96ccb01:cznic_sqlite/vendor/modernc.org/sqlite \
		cznic:strutil:9654ad6deeb404d1ca68c1d66d008bbaf3e2c50e:cznic_strutil/vendor/modernc.org/strutil \
		cznic:token:46658f20d51b8d0b6c4c551c363c8510c30c2a72:cznic_token/vendor/modernc.org/token

		# Errors found during processing:
		#	tag v2.6.0 doesn't seem to exist in sensu/sensu-go

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_bigquery}/bigquery ${WRKSRC}/vendor/cloud.google.com/go/bigquery
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_pubsub}/pubsub ${WRKSRC}/vendor/cloud.google.com/go/pubsub
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RLN} ${WRKSRC_azure_go_autorest_autorest}/autorest ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RLN} ${WRKSRC_azure_go_autorest_adal}/autorest/adal ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/adal
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RLN} ${WRKSRC_azure_go_autorest_auth}/autorest/azure/auth ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/auth
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RLN} ${WRKSRC_azure_go_autorest_cli}/autorest/azure/cli ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/azure/cli
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RLN} ${WRKSRC_azure_go_autorest_date}/autorest/date ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/date
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/to
	@${RLN} ${WRKSRC_azure_go_autorest_to}/autorest/to ${WRKSRC}/vendor/github.com/Azure/go-autorest/autorest/to
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ec2
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_ec2}/service/ec2 ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/ec2
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/config
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_config}/config ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/config
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_credentials}/credentials ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/credentials
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/s3
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_s3}/service/s3 ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/s3
	@${RM} -r ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/s3shared
	@${RLN} ${WRKSRC_aws_aws_sdk_go_v2_s3shared}/service/internal/s3shared ${WRKSRC}/vendor/github.com/aws/aws-sdk-go-v2/service/internal/s3shared
	@${RM} -r ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${RLN} ${WRKSRC_moby_sys_mountinfo}/mountinfo ${WRKSRC}/vendor/github.com/moby/sys/mountinfo
	@${MKDIR} ${WRKSRC}/vendor/github.com/vishvananda
	@${RLN} ${WRKSRC_mdlayher_netlink} ${WRKSRC}/vendor/github.com/vishvananda/netlink

post-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}
	${INSTALL_DATA} \
		${WRKSRC}/${GH_SUBDIR}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
