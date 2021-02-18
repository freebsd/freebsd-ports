# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
DISTVERSIONPREFIX=v
DISTVERSION=	1.17.3
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
GH_TUPLE=	\
		Azure:azure-amqp-common-go:v3.0.0:azure_azure_amqp_common_go_v3/vendor/github.com/Azure/azure-amqp-common-go/v3 \
		Azure:azure-event-hubs-go:v3.2.0:azure_azure_event_hubs_go_v3/vendor/github.com/Azure/azure-event-hubs-go/v3 \
		Azure:azure-pipeline-go:v0.1.9:azure_azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-sdk-for-go:v37.1.0:azure_azure_sdk_for_go/vendor/github.com/Azure/azure-sdk-for-go \
		Azure:azure-storage-queue-go:6ed74e755687:azure_azure_storage_queue_go/vendor/github.com/Azure/azure-storage-queue-go \
		Azure:go-amqp:v0.12.6:azure_go_amqp/vendor/github.com/Azure/go-amqp \
		Azure:go-ansiterm:d6e3b3328b78:azure_go_ansiterm/vendor/github.com/Azure/go-ansiterm \
		Azure:go-autorest:5bd9621f41a0:azure_go_autorest_date/vendor/github.com/Azure/go-autorest \
		Azure:go-autorest:aff029487b89:azure_go_autorest_adal \
		Azure:go-autorest:autorest/v0.9.3:azure_go_autorest_autorest \
		Azure:go-autorest:b965d219bd9d:azure_go_autorest_auth \
		Azure:go-autorest:cc407fb4f94c:azure_go_autorest_cli \
		Azure:go-autorest:logger/v0.1.0:azure_go_autorest_logger \
		Azure:go-autorest:tracing/v0.5.0:azure_go_autorest_tracing \
		BurntSushi:toml:v0.3.1:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		Mellanox:rdmamap:7c3c4763a6ee:mellanox_rdmamap/vendor/github.com/Mellanox/rdmamap \
		Microsoft:ApplicationInsights-Go:v0.4.2:microsoft_applicationinsights_go/vendor/github.com/Microsoft/ApplicationInsights-Go \
		Microsoft:go-winio:v0.4.9:microsoft_go_winio/vendor/github.com/Microsoft/go-winio \
		Shopify:sarama:v1.27.2:shopify_sarama/vendor/github.com/Shopify/sarama \
		StackExchange:wmi:5d049714c4a6:stackexchange_wmi/vendor/github.com/StackExchange/wmi \
		aerospike:aerospike-client-go:v1.27.0:aerospike_aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		alecthomas:units:c3de453c63f4:alecthomas_units/vendor/github.com/alecthomas/units \
		amir:raidman:1ccc43bfb9c9:amir_raidman/vendor/github.com/amir/raidman \
		apache:thrift:v0.12.0:apache_thrift/vendor/github.com/apache/thrift \
		aristanetworks:glog:67e8567f59f3:aristanetworks_glog/vendor/github.com/aristanetworks/glog \
		aristanetworks:goarista:a123909ec740:aristanetworks_goarista/vendor/github.com/aristanetworks/goarista \
		armon:go-metrics:v0.3.0:armon_go_metrics/vendor/github.com/armon/go-metrics \
		aws:aws-sdk-go:v1.34.34:aws_aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		benbjohnson:clock:v1.0.3:benbjohnson_clock/vendor/github.com/benbjohnson/clock \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bitly:go-hostpool:v0.1.0:bitly_go_hostpool/vendor/github.com/bitly/go-hostpool \
		bmizerany:assert:b7ed37b82869:bmizerany_assert/vendor/github.com/bmizerany/assert \
		caio:go-tdigest:v2.3.0:caio_go_tdigest/vendor/github.com/caio/go-tdigest \
		cenkalti:backoff:v2.0.0:cenkalti_backoff/vendor/github.com/cenkalti/backoff \
		census-instrumentation:opencensus-go:v0.22.3:census_instrumentation_opencensus_go/vendor/go.opencensus.io \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		cisco-ie:nx-telemetry-proto:82441e232cf6:cisco_ie_nx_telemetry_proto/vendor/github.com/cisco-ie/nx-telemetry-proto \
		cloudfoundry:clock:v1.0.0:cloudfoundry_clock/vendor/code.cloudfoundry.org/clock \
		cockroachdb:apd:v1.1.0:cockroachdb_apd/vendor/github.com/cockroachdb/apd \
		collectd:go-collectd:v0.3.0:collectd_go_collectd/vendor/collectd.org \
		containerd:containerd:v1.4.1:containerd_containerd/vendor/github.com/containerd/containerd \
		couchbase:go-couchbase:16db1f1fe037:couchbase_go_couchbase/vendor/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:0da75df14530:couchbase_gomemcached/vendor/github.com/couchbase/gomemcached \
		couchbase:goutils:e865a1461c8a:couchbase_goutils/vendor/github.com/couchbase/goutils \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:2be1aa521ff4:denisenkom_go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		devigned:tab:v0.1.1:devigned_tab/vendor/github.com/devigned/tab \
		dgrijalva:jwt-go:v3.2.0:dgrijalva_jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dgrijalva:jwt-go:v4.0.0-preview1:dgrijalva_jwt_go_v4/vendor/github.com/dgrijalva/jwt-go/v4 \
		dimchansky:utfbom:v1.1.0:dimchansky_utfbom/vendor/github.com/dimchansky/utfbom \
		docker:distribution:edc3ab29cdff:docker_distribution/vendor/github.com/docker/distribution \
		docker:go-connections:v0.3.0:docker_go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.3:docker_go_units/vendor/github.com/docker/go-units \
		docker:libnetwork:d7b61745d166:docker_libnetwork/vendor/github.com/docker/libnetwork \
		dominikh:go-tools:v0.0.1-2020.1.3:dominikh_go_tools/vendor/honnef.co/go/tools \
		eapache:go-resiliency:v1.2.0:eapache_go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:776d5712da21:eapache_go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:eapache_queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:v1.2.0:eclipse_paho_mqtt_golang/vendor/github.com/eclipse/paho.mqtt.golang \
		ericchiang:k8s:v1.2.0:ericchiang_k8s/vendor/github.com/ericchiang/k8s \
		fatih:pool:v2.0.0:fatih_pool/vendor/gopkg.in/fatih/pool.v2 \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		ghodss:yaml:25d852aebe32:ghodss_yaml/vendor/github.com/ghodss/yaml \
		go-asn1-ber:asn1-ber:f715ec2f112d:go_asn1_ber_asn1_ber/vendor/gopkg.in/asn1-ber.v1 \
		go-inf:inf:v0.9.1:go_inf_inf/vendor/gopkg.in/inf.v0 \
		go-ldap:ldap:v3.1.0:go_ldap_ldap/vendor/gopkg.in/ldap.v3 \
		go-logfmt:logfmt:v0.4.0:go_logfmt_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-mgo:mgo:9856a29383ce:go_mgo_mgo/vendor/gopkg.in/mgo.v2 \
		go-ole:go-ole:v1.2.1:go_ole_go_ole/vendor/github.com/go-ole/go-ole \
		go-ping:ping:3300c582a663:go_ping_ping/vendor/github.com/go-ping/ping \
		go-redis:redis:v6.15.9:go_redis_redis/vendor/github.com/go-redis/redis \
		go-sql-driver:mysql:v1.5.0:go_sql_driver_mysql/vendor/github.com/go-sql-driver/mysql \
		go-tomb:tomb:d5d1b5820637:go_tomb_tomb_1/vendor/gopkg.in/tomb.v2 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:eeeca48fe776:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		go-yaml:yaml:v2.2.8:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		goburrow:modbus:v0.1.0:goburrow_modbus/vendor/github.com/goburrow/modbus \
		goburrow:serial:v0.1.0:goburrow_serial/vendor/github.com/goburrow/serial \
		gobwas:glob:v0.2.3:gobwas_glob/vendor/github.com/gobwas/glob \
		gofrs:uuid:v2.1.0:gofrs_uuid_1/vendor/github.com/gofrs/uuid \
		gofrs:uuid:v3.2.0:gofrs_uuid/vendor/github.com/satori/go.uuid \
		gogo:protobuf:65acae22fc9d:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:appengine:v1.6.5:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:5c72a883971a:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:6cc2880d07d6:golang_exp/vendor/golang.org/x/exp \
		golang:geo:5b978397cfec:golang_geo/vendor/github.com/golang/geo \
		golang:groupcache:8c9f03a8e57e:golang_groupcache/vendor/github.com/golang/groupcache \
		golang:lint:738671d3881b:golang_lint/vendor/golang.org/x/lint \
		golang:mod:v0.2.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:62affa334b73:golang_net/vendor/golang.org/x/net \
		golang:oauth2:bf48bf16ab8d:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.3.5:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:v0.0.1:golang_snappy/vendor/github.com/golang/snappy \
		golang:sync:43a5402ce75a:golang_sync/vendor/golang.org/x/sync \
		golang:sys:f9321e4c35a6:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.3:golang_text/vendor/golang.org/x/text \
		golang:time:555d28b269f0:golang_time/vendor/golang.org/x/time \
		golang:tools:63da46f3035e:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		google:go-cmp:v0.5.2:google_go_cmp/vendor/github.com/google/go-cmp \
		google:go-genproto:09dca8ec2884:google_go_genproto/vendor/google.golang.org/genproto \
		google:go-github:v32.1.0:google_go_github_v32/vendor/github.com/google/go-github/v32 \
		google:go-querystring:v1.0.0:google_go_querystring/vendor/github.com/google/go-querystring \
		google:starlark-go:6e684ef5eeee:google_starlark_go/vendor/go.starlark.net \
		google:uuid:v1.1.2:google_uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.5:googleapis_gax_go_v2/vendor/github.com/googleapis/gax-go \
		googleapis:google-api-go-client:v0.20.0:googleapis_google_api_go_client/vendor/google.golang.org/api \
		googleapis:google-cloud-go:datastore/v1.1.0:googleapis_google_cloud_go_datastore \
		googleapis:google-cloud-go:pubsub/v1.2.0:googleapis_google_cloud_go_pubsub \
		googleapis:google-cloud-go:v0.53.0:googleapis_google_cloud_go/vendor/cloud.google.com/go \
		gopcua:opcua:v0.1.13:gopcua_opcua/vendor/github.com/gopcua/opcua \
		rethinkdb:rethinkdb-go:v3.0.5:gorethink_gorethink/vendor/gopkg.in/gorethink/gorethink.v3 \
		gorilla:context:v1.1.1:gorilla_context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.6.2:gorilla_mux/vendor/github.com/gorilla/mux \
		gosnmp:gosnmp:v1.29.0:gosnmp_gosnmp/vendor/github.com/gosnmp/gosnmp \
		gotestyourself:gotest.tools:v2.2.0:gotestyourself_gotest_tools/vendor/gotest.tools \
		grpc-ecosystem:grpc-gateway:v1.16.0:grpc_ecosystem_grpc_gateway/vendor/github.com/grpc-ecosystem/grpc-gateway \
		grpc:grpc-go:v1.33.1:grpc_grpc_go/vendor/google.golang.org/grpc \
		hailocab:go-hostpool:e80d13ce29ed:hailocab_go_hostpool/vendor/github.com/hailocab/go-hostpool \
		harlow:kinesis-consumer:2f58b136fee0:harlow_kinesis_consumer/vendor/github.com/harlow/kinesis-consumer \
		hashicorp:consul:v1.2.1:hashicorp_consul/vendor/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:v0.5.0:hashicorp_go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-msgpack:v0.5.5:hashicorp_go_msgpack/vendor/github.com/hashicorp/go-msgpack \
		hashicorp:go-rootcerts:6bb64b370b90:hashicorp_go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-uuid:v1.0.2:hashicorp_go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:memberlist:v0.1.5:hashicorp_memberlist/vendor/github.com/hashicorp/memberlist \
		hashicorp:serf:v0.8.1:hashicorp_serf/vendor/github.com/hashicorp/serf \
		influxdata:go-syslog:v2.0.1:influxdata_go_syslog_v2/vendor/github.com/influxdata/go-syslog/v2 \
		influxdata:tail:03a791b270e4:influxdata_tail/vendor/github.com/influxdata/tail \
		influxdata:toml:270119a8ce65:influxdata_toml/vendor/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a71ef8:influxdata_wlog/vendor/github.com/influxdata/wlog \
		jackc:fake:812a484cc733:jackc_fake/vendor/github.com/jackc/fake \
		jackc:pgx:v3.6.0:jackc_pgx/vendor/github.com/jackc/pgx \
		jcmturner:aescts:v1.0.1:jcmturner_aescts/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:jcmturner_dnsutils/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gofork:v1.0.0:jcmturner_gofork/vendor/github.com/jcmturner/gofork \
		jcmturner:gokrb5:v7.5.0:jcmturner_gokrb5/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:jcmturner_rpc/vendor/gopkg.in/jcmturner/rpc.v1 \
		jmespath:go-jmespath:v0.4.0:jmespath_go_jmespath/vendor/github.com/jmespath/go-jmespath \
		jpillora:backoff:3050d21c67d7:jpillora_backoff/vendor/github.com/jpillora/backoff \
		jstemmer:go-junit-report:v0.9.1:jstemmer_go_junit_report/vendor/github.com/jstemmer/go-junit-report \
		kardianos:service:v1.0.0:kardianos_service/vendor/github.com/kardianos/service \
		karrick:godirwalk:v1.16.1:karrick_godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.11.0:klauspost_compress/vendor/github.com/klauspost/compress \
		konsorten:go-windows-terminal-sequences:v1.0.1:konsorten_go_windows_terminal_sequences/vendor/github.com/konsorten/go-windows-terminal-sequences \
		kr:logfmt:b84e30acd515:kr_logfmt/vendor/github.com/kr/logfmt \
		kr:pretty:v0.2.1:kr_pretty/vendor/github.com/kr/pretty \
		kr:text:v0.2.0:kr_text/vendor/github.com/kr/text \
		kubernetes:apimachinery:d41becfba9ee:kubernetes_apimachinery/vendor/github.com/kubernetes/apimachinery \
		kubernetes:apimachinery:v0.17.1:kubernetes_apimachinery_1/vendor/k8s.io/apimachinery \
		kylelemons:godebug:v1.1.0:kylelemons_godebug/vendor/github.com/kylelemons/godebug \
		leesper:go_rng:a612b043e353:leesper_go_rng/vendor/github.com/leesper/go_rng \
		leodido:ragel-machinery:299bdde78165:leodido_ragel_machinery/vendor/github.com/leodido/ragel-machinery \
		lib:pq:v1.3.0:lib_pq/vendor/github.com/lib/pq \
		mailru:easyjson:efc7eb8984d6:mailru_easyjson/vendor/github.com/mailru/easyjson \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mdlayher:apcupsd:2bf01da7bf1b:mdlayher_apcupsd/vendor/github.com/mdlayher/apcupsd \
		mdlayher:genetlink:v1.0.0:mdlayher_genetlink/vendor/github.com/mdlayher/genetlink \
		mdlayher:netlink:v1.1.0:mdlayher_netlink/vendor/github.com/mdlayher/netlink \
		miekg:dns:v1.0.14:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-testing-interface:v1.0.0:mitchellh_go_testing_interface/vendor/github.com/mitchellh/go-testing-interface \
		mitchellh:mapstructure:v1.1.2:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		moby:moby:bd33bbf0497b:docker_docker/vendor/github.com/docker/docker \
		morikuni:aec:v1.0.0:morikuni_aec/vendor/github.com/morikuni/aec \
		multiplay:go-ts3:v1.0.0:multiplay_go_ts3/vendor/github.com/multiplay/go-ts3 \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		nats-io:jwt:v0.3.2:nats_io_jwt/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.1.4:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.9.1:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.1.3:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		newrelic:newrelic-telemetry-sdk-go:v0.5.1:newrelic_newrelic_telemetry_sdk_go/vendor/github.com/newrelic/newrelic-telemetry-sdk-go \
		nsqio:go-nsq:v1.0.8:nsqio_go_nsq/vendor/github.com/nsqio/go-nsq \
		olivere:elastic:v5.0.70:olivere_elastic/vendor/gopkg.in/olivere/elastic.v5 \
		openconfig:gnmi:33a1865c3029:openconfig_gnmi/vendor/github.com/openconfig/gnmi \
		opencontainers:go-digest:v1.0.0-rc1:opencontainers_go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:opencontainers_image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing-contrib:go-observer:a52f23424492:opentracing_contrib_go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.0.2:opentracing_opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:openzipkin_zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing \
		pierrec:lz4:v2.5.2:pierrec_lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.5.1:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.9.1:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.0.8:prometheus_procfs/vendor/github.com/prometheus/procfs \
		prometheus:prometheus:v2.5.0:prometheus_prometheus/vendor/github.com/prometheus/prometheus \
		rcrowley:go-metrics:10cdbea86bc0:rcrowley_go_metrics/vendor/github.com/rcrowley/go-metrics \
		riemann:riemann-go-client:v0.5.0:riemann_riemann_go_client/vendor/github.com/riemann/riemann-go-client \
		safchain:ethtool:f459e2d13664:safchain_ethtool/vendor/github.com/safchain/ethtool \
		samuel:go-zookeeper:c4fab1ac1bec:samuel_go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		shirou:gopsutil:v2.20.9:shirou_gopsutil/vendor/github.com/shirou/gopsutil \
		shopspring:decimal:408a2507e114:shopspring_decimal/vendor/github.com/shopspring/decimal \
		sirupsen:logrus:v1.4.2:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		soniah:gosnmp:v1.25.0:soniah_gosnmp/vendor/github.com/soniah/gosnmp \
		streadway:amqp:e5adc2ada8b8:streadway_amqp/vendor/github.com/streadway/amqp \
		stretchr:objx:v0.1.1:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tbrandon:mbserver:993e1772cc62:tbrandon_mbserver/vendor/github.com/tbrandon/mbserver \
		tedsuo:ifrit:9a97d0632f00:tedsuo_ifrit/vendor/github.com/tedsuo/ifrit \
		tidwall:gjson:v1.6.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:v1.0.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		vishvananda:netlink:b2de5d10e38e:vishvananda_netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:13995c7128cc:vishvananda_netns/vendor/github.com/vishvananda/netns \
		vjeantet:grok:v1.0.1:vjeantet_grok/vendor/github.com/vjeantet/grok \
		vmware:govmomi:v0.19.0:vmware_govmomi/vendor/github.com/vmware/govmomi \
		wavefronthq:wavefront-sdk-go:v0.9.2:wavefronthq_wavefront_sdk_go/vendor/github.com/wavefronthq/wavefront-sdk-go \
		WireGuard:wireguard-go:v0.0.20200121:WireGuard_wireguard_go/vendor/golang.zx2c4.com/wireguard \
		WireGuard:wgctrl-go:e35592f146e4:WireGuard_wgctrl_go/vendor/golang.zx2c4.com/wireguard/wgctrl \
		wvanbergen:kafka:e2edea948ddf:wvanbergen_kafka/vendor/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:f72d8611297a:wvanbergen_kazoo_go/vendor/github.com/wvanbergen/kazoo-go \
		xdg:scram:7eeb5667e42c:xdg_scram/vendor/github.com/xdg/scram \
		xdg:stringprep:v1.0.0:xdg_stringprep/vendor/github.com/xdg/stringprep \
		yuin:gopher-lua:46796da1b0b4:yuin_gopher_lua/vendor/github.com/yuin/gopher-lua

GL_TUPLE=	cznic:libc:b3aa1596bd495d3feff88f563519b18c92b399ce:cznic_libc/vendor/modernc.org/libc \
		cznic:memory:456baf95175317ca2a91a541bfaba19151a9d817:cznic_memory/vendor/modernc.org/memory \
		cznic:sqlite:91fc7a88e5cbcb745d181771500efedfd798f2e3:cznic_sqlite/vendor/modernc.org/sqlite

post-extract:
	@${RM} -r ${WRKSRC}/vendor/cloud.google.com/go/datastore
	@${RLN} ${WRKSRC_googleapis_google_cloud_go_datastore}/datastore ${WRKSRC}/vendor/cloud.google.com/go/datastore
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
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RLN} ${WRKSRC_azure_go_autorest_logger}/logger ${WRKSRC}/vendor/github.com/Azure/go-autorest/logger
	@${RM} -r ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing
	@${RLN} ${WRKSRC_azure_go_autorest_tracing}/tracing ${WRKSRC}/vendor/github.com/Azure/go-autorest/tracing

post-patch:
	${RM} -r ${SRKSRC}/vendor/github.com/miekg/dns/vendor/golang.org/x/net
	${CP} -R ${WRKDIR}/net-62affa334b73/* ${WRKSRC}/vendor/github.com/miekg/dns/vendor/golang.org/x/net

post-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}
	${INSTALL_DATA} \
		${WRKSRC}/${GH_SUBDIR}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
