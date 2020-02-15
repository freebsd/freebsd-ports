# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
DISTVERSION=	1.13.3
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 armv6 armv7 i386

USES=		go

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}
GH_TUPLE=	GoogleCloudPlatform:google-cloud-go:v0.27.0:go/vendor/cloud.google.com/go \
		cloudfoundry:clock:02e53af:clock/vendor/code.cloudfoundry.org/clock \
		collectd:go-collectd:v0.3.0:collectd0org/vendor/collectd.org \
		census-ecosystem:opencensus-go-exporter-stackdriver:v0.6.0:census_ecosystem/vendor/contrib.go.opencensus.io/exporter/stackdriver \
		Azure:azure-pipeline-go:v0.1.8:azure_pipeline_go/vendor/github.com/Azure/azure-pipeline-go \
		Azure:azure-storage-queue-go:0.2.0:azure_storage_queue_go/vendor/github.com/Azure/azure-storage-queue-go \
		Azure:go-autorest:v13.3.0:go_autorest/vendor/github.com/Azure/go-autorest \
		Microsoft:ApplicationInsights-Go:v0.4.2:application_insights/vendor/github.com/Microsoft/ApplicationInsights-Go \
		Microsoft:go-winio:v0.4.9:go_winio/vendor/github.com/Microsoft/go-winio \
		Shopify:sarama:v1.24.1:sarama/vendor/github.com/Shopify/sarama \
		StackExchange:wmi:1.0.0:wmi/vendor/github.com/StackExchange/wmi \
		aerospike:aerospike-client-go:v1.27.0:aerospike_client_go/vendor/github.com/aerospike/aerospike-client-go \
		alecthomas:units:2efee85:units/vendor/github.com/alecthomas/units \
		amir:raidman:1ccc43b:raidman/vendor/github.com/amir/raidman \
		apache:thrift:f2867c2:thrift/vendor/github.com/apache/thrift \
		aws:aws-sdk-go:v1.19.41:aws_sdk_go/vendor/github.com/aws/aws-sdk-go \
		beorn7:perks:3a771d9:perks/vendor/github.com/beorn7/perks \
		caio:go-tdigest:v2.3.0:go_tdigest/vendor/github.com/caio/go-tdigest \
		cenkalti:backoff:v2.0.0:backoff/vendor/github.com/cenkalti/backoff \
		cisco-ie:nx-telemetry-proto:82441e2:nx_telemetry_proto/vendor/github.com/cisco-ie/nx-telemetry-proto \
		couchbase:go-couchbase:16db1f1:go_couchbase/vendor/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:0da75df:gomemcached/vendor/github.com/couchbase/gomemcached \
		couchbase:goutils:e865a14:goutils/vendor/github.com/couchbase/goutils \
		davecgh:go-spew:v1.1.0:go_spew/vendor/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:2be1aa5:go_mssqldb/vendor/github.com/denisenkom/go-mssqldb \
		dgrijalva:jwt-go:v3.2.0:jwt_go/vendor/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:v1.1.0:utfbom/vendor/github.com/dimchansky/utfbom \
		docker:distribution:edc3ab2:distribution/vendor/github.com/docker/distribution \
		moby:moby:ed7b642:docker/vendor/github.com/docker/docker \
		docker:go-connections:v0.3.0:go_connections/vendor/github.com/docker/go-connections \
		docker:go-units:v0.3.3:go_units/vendor/github.com/docker/go-units \
		docker:libnetwork:d7b6174:libnetwork/vendor/github.com/docker/libnetwork \
		eapache:go-resiliency:v1.1.0:go_resiliency/vendor/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:040cc1a:go_xerial_snappy/vendor/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:queue/vendor/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:v1.2.0:paho0mqtt0golang/vendor/github.com/eclipse/paho.mqtt.golang \
		ericchiang:k8s:v1.2.0:k8s/vendor/github.com/ericchiang/k8s \
		ghodss:yaml:25d852a:yaml/vendor/github.com/ghodss/yaml \
		glinton:ping:v0.1.3:ping/vendor/github.com/glinton/ping \
		go-logfmt:logfmt:v0.4.0:go_logfmt/vendor/github.com/go-logfmt/logfmt \
		go-ole:go-ole:v1.2.1:go_ole/vendor/github.com/go-ole/go-ole \
		go-redis:redis:v6.12.0:redis/vendor/github.com/go-redis/redis \
		go-sql-driver:mysql:v1.4.1:mysql/vendor/github.com/go-sql-driver/mysql \
		gobwas:glob:v0.2.3:glob/vendor/github.com/gobwas/glob \
		gofrs:uuid:v2.1.0:gofrs_uuid/vendor/github.com/gofrs/uuid \
		gogo:protobuf:v1.1.1:gogo_protobuf/vendor/github.com/gogo/protobuf \
		golang:mock:1.3.1:mock/vendor/github.com/golang/mock \
		golang:protobuf:v1.1.0:protobuf/vendor/github.com/golang/protobuf \
		golang:snappy:2e65f85:snappy/vendor/github.com/golang/snappy \
		google:go-cmp:v0.2.0:go_cmp/vendor/github.com/google/go-cmp \
		google:go-github:v24.0.1:go_github/vendor/github.com/google/go-github \
		google:go-querystring:v1.0.0:go_querystring/vendor/github.com/google/go-querystring \
		google:uuid:0.2:uuid/vendor/github.com/google/uuid \
		googleapis:gax-go:v2.0.0:gax_go/vendor/github.com/googleapis/gax-go \
		gorilla:context:v1.1.1:context/vendor/github.com/gorilla/context \
		gorilla:mux:v1.6.2:mux/vendor/github.com/gorilla/mux \
		hailocab:go-hostpool:e80d13c:go_hostpool/vendor/github.com/hailocab/go-hostpool \
		harlow:kinesis-consumer:2f58b13:kinesis_consumer/vendor/github.com/harlow/kinesis-consumer \
		hashicorp:consul:v1.2.1:consul/vendor/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:d5fe4b5:go_cleanhttp/vendor/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-rootcerts:6bb64b3:go_rootcerts/vendor/github.com/hashicorp/go-rootcerts \
		hashicorp:go-uuid:v1.0.1:go_uuid/vendor/github.com/hashicorp/go-uuid \
		hashicorp:serf:v0.8.1:serf/vendor/github.com/hashicorp/serf \
		influxdata:go-syslog:v2.0.0:go_syslog/vendor/github.com/influxdata/go-syslog \
		influxdata:tail:c434825:tail/vendor/github.com/influxdata/tail \
		influxdata:toml:270119a:toml/vendor/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a:wlog/vendor/github.com/influxdata/wlog \
		jackc:pgx:v3.6.0:pgx/vendor/github.com/jackc/pgx \
		jcmturner:gofork:v1.0.0:gofork/vendor/github.com/jcmturner/gofork \
		jmespath:go-jmespath:c2b33e8:go_jmespath/vendor/github.com/jmespath/go-jmespath \
		kardianos:service:v1.0.0:service/vendor/github.com/kardianos/service \
		karrick:godirwalk:v1.12.0:godirwalk/vendor/github.com/karrick/godirwalk \
		kballard:go-shellquote:95032a8:go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.9.2:compress/vendor/github.com/klauspost/compress \
		kr:logfmt:b84e30a:logfmt/vendor/github.com/kr/logfmt \
		kubernetes:apimachinery:d41becf:apimachinery/vendor/github.com/kubernetes/apimachinery \
		leodido:ragel-machinery:299bdde:ragel_machinery/vendor/github.com/leodido/ragel-machinery \
		mailru:easyjson:efc7eb8:easyjson/vendor/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		mdlayher:apcupsd:eb3dd99:apcupsd/vendor/github.com/mdlayher/apcupsd \
		miekg:dns:v1.0.10:dns/vendor/github.com/miekg/dns \
		mitchellh:go-homedir:v1.1.0:go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:f15292f:mapstructure/vendor/github.com/mitchellh/mapstructure \
		multiplay:go-ts3:v1.0.0:go_ts3/vendor/github.com/multiplay/go-ts3 \
		naoina:go-stringutil:v0.1.0:go_stringutil/vendor/github.com/naoina/go-stringutil \
		nats-io:nats-server:v1.2.0:gnatsd/vendor/github.com/nats-io/gnatsd \
		nats-io:go-nats:v1.5.0:nats/vendor/github.com/nats-io/go-nats \
		nats-io:nuid:v1.0.0:nuid/vendor/github.com/nats-io/nuid \
		nsqio:go-nsq:v1.0.7:go_nsq/vendor/github.com/nsqio/go-nsq \
		openconfig:gnmi:33a1865:gnmi/vendor/github.com/openconfig/gnmi \
		opencontainers:go-digest:v1.0.0-rc1:go_digest/vendor/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:image_spec/vendor/github.com/opencontainers/image-spec \
		opentracing-contrib:go-observer:a52f234:go_observer/vendor/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.0.2:opentracing_go/vendor/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:zipkin_go_opentracing/vendor/github.com/openzipkin/zipkin-go-opentracing \
		pierrec:lz4:v2.0.3:lz4/vendor/github.com/pierrec/lz4 \
		pkg:errors:v0.8.0:errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.9.2:client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d:client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:7600349:common/vendor/github.com/prometheus/common \
		prometheus:procfs:ae68e2d:procfs/vendor/github.com/prometheus/procfs \
		rcrowley:go-metrics:e2704e1:go_metrics/vendor/github.com/rcrowley/go-metrics \
		safchain:ethtool:ef7e7c9:ethtool/vendor/github.com/safchain/ethtool \
		samuel:go-zookeeper:c4fab1a:go_zookeeper/vendor/github.com/samuel/go-zookeeper \
		satori:go.uuid:b2ce238:go0uuid/vendor/github.com/satori/go.uuid \
		shirou:gopsutil:v2.19.11:gopsutil/vendor/github.com/shirou/gopsutil \
		shirou:w32:bb4de01:w32/vendor/github.com/shirou/w32 \
		sirupsen:logrus:v1.0.5:logrus/vendor/github.com/sirupsen/logrus \
		soniah:gosnmp:v1.22.0:gosnmp/vendor/github.com/soniah/gosnmp \
		streadway:amqp:e5adc2a:amqp/vendor/github.com/streadway/amqp \
		stretchr:objx:v0.1.1:objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.2.2:testify/vendor/github.com/stretchr/testify \
		tidwall:gjson:v1.3.0:gjson/vendor/github.com/tidwall/gjson \
		tidwall:match:1731857:match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.0.0:pretty/vendor/github.com/tidwall/pretty \
		vishvananda:netlink:b2de5d1:netlink/vendor/github.com/vishvananda/netlink \
		vishvananda:netns:13995c7:netns/vendor/github.com/vishvananda/netns \
		vjeantet:grok:v1.0.0:grok/vendor/github.com/vjeantet/grok \
		vmware:govmomi:v0.19.0:govmomi/vendor/github.com/vmware/govmomi \
		wavefronthq:wavefront-sdk-go:v0.9.2:wavefront_sdk_go/vendor/github.com/wavefronthq/wavefront-sdk-go \
		wvanbergen:kafka:e2edea9:kafka/vendor/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:f72d861:kazoo_go/vendor/github.com/wvanbergen/kazoo-go \
		yuin:gopher-lua:46796da:gopher_lua/vendor/github.com/yuin/gopher-lua \
		census-instrumentation:opencensus-go:v0.17.0:opencensus_go/vendor/go.opencensus.io \
		golang:crypto:87dc89f:crypto/vendor/golang.org/x/crypto \
		golang:net:a680a1e:net/vendor/golang.org/x/net \
		golang:oauth2:d2e6202:oauth2/vendor/golang.org/x/oauth2 \
		golang:sync:42b3178:sync/vendor/golang.org/x/sync \
		golang:sys:51ab0e2:sys/vendor/golang.org/x/sys \
		golang:text:v0.3.0:text/vendor/golang.org/x/text \
		googleapis:google-api-go-client:19ff876:googleapis/vendor/google.golang.org/api \
		golang:appengine:v1.1.0:appengine/vendor/google.golang.org/appengine \
		google:go-genproto:fedd286:genproto/vendor/google.golang.org/genproto \
		grpc:grpc-go:v1.13.0:grpc/vendor/google.golang.org/grpc \
		go-asn1-ber:asn1-ber:v1.2:asn1_ber0v1/vendor/gopkg.in/asn1-ber.v1 \
		fatih:pool:v2.0.0:pool0v2/vendor/gopkg.in/fatih/pool.v2 \
		fsnotify:fsnotify:v1.4.7:fsnotify0v1/vendor/gopkg.in/fsnotify.v1 \
		rethinkdb:rethinkdb-go:v3.0.5:gorethink0v3/vendor/gopkg.in/gorethink/gorethink.v3 \
		go-inf:inf:v0.9.1:inf0v0/vendor/gopkg.in/inf.v0 \
		jcmturner:aescts:v1.0.1:aescts0v1/vendor/gopkg.in/jcmturner/aescts.v1 \
		jcmturner:dnsutils:v1.0.1:dnsutils0v1/vendor/gopkg.in/jcmturner/dnsutils.v1 \
		jcmturner:gokrb5:v7.3.0:gokrb50v7/vendor/gopkg.in/jcmturner/gokrb5.v7 \
		jcmturner:rpc:v1.1.0:rpc0v1/vendor/gopkg.in/jcmturner/rpc.v1 \
		go-ldap:ldap:v3.1.0:ldap0v3/vendor/gopkg.in/ldap.v3 \
		go-mgo:mgo:9856a29:mgo0v2/vendor/gopkg.in/mgo.v2 \
		olivere:elastic:v5.0.70:elastic0v5/vendor/gopkg.in/olivere/elastic.v5 \
		go-tomb:tomb:dd63297:tomb0v1/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.1:yaml0v2/vendor/gopkg.in/yaml.v2

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"
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

post-patch:
	${CP} ${WRKSRC_gopsutil}/disk/disk_freebsd_386.go ${WRKSRC_gopsutil}/disk/disk_freebsd_arm.go
	${CP} ${WRKSRC_gopsutil}/cpu/cpu_freebsd_386.go ${WRKSRC_gopsutil}/cpu/cpu_freebsd_arm.go
#	${LN} -s . ${WRKSRC_go_syslog}/v2

post-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}
	${INSTALL_DATA} \
		${WRKSRC}/${GH_SUBDIR}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
