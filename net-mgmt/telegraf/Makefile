# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
DISTVERSION=	1.9.0
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	go>=1.9:lang/go

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata
GH_SUBDIR=	src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT_DEFAULT}
GH_TUPLE=	GoogleCloudPlatform:google-cloud-go:v0.27.0:go/src/cloud.google.com/go \
		cloudfoundry:clock:02e53af:clock/src/code.cloudfoundry.org/clock \
		collectd:go-collectd:v0.3.0:collectd_org/src/collectd.org \
		census-ecosystem:opencensus-go-exporter-stackdriver:v0.6.0:census_ecosystem/src/contrib.go.opencensus.io/exporter/stackdriver \
		Azure:go-autorest:v10.12.0:go_autorest/src/github.com/Azure/go-autorest \
		Microsoft:ApplicationInsights-Go:d2df5d4:application_insights/src/github.com/Microsoft/ApplicationInsights-Go \
		Microsoft:go-winio:v0.4.9:go_winio/src/github.com/Microsoft/go-winio \
		Shopify:sarama:v1.18.0:sarama/src/github.com/Shopify/sarama \
		StackExchange:wmi:1.0.0:wmi/src/github.com/StackExchange/wmi \
		aerospike:aerospike-client-go:v1.27.0:aerospike_client_go/src/github.com/aerospike/aerospike-client-go \
		alecthomas:template:a0175ee:template/src/github.com/alecthomas/template \
		alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		amir:raidman:1ccc43b:raidman/src/github.com/amir/raidman \
		apache:thrift:f2867c2:thrift/src/github.com/apache/thrift \
		aws:aws-sdk-go:v1.15.54:aws_sdk_go/src/github.com/aws/aws-sdk-go \
		beorn7:perks:3a771d9:perks/src/github.com/beorn7/perks \
		bsm:sarama-cluster:v2.1.13:sarama_cluster/src/github.com/bsm/sarama-cluster \
		cenkalti:backoff:v2.0.0:backoff/src/github.com/cenkalti/backoff \
		couchbase:go-couchbase:16db1f1:go_couchbase/src/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:0da75df:gomemcached/src/github.com/couchbase/gomemcached \
		couchbase:goutils:e865a14:goutils/src/github.com/couchbase/goutils \
		davecgh:go-spew:v1.1.0:go_spew/src/github.com/davecgh/go-spew \
		denisenkom:go-mssqldb:1eb28af:go_mssqldb/src/github.com/denisenkom/go-mssqldb \
		dgrijalva:jwt-go:v3.2.0:jwt_go/src/github.com/dgrijalva/jwt-go \
		dimchansky:utfbom:6c6132f:utfbom/src/github.com/dimchansky/utfbom \
		docker:distribution:edc3ab2:distribution/src/github.com/docker/distribution \
		moby:moby:ed7b642:docker/src/github.com/docker/docker \
		docker:go-connections:v0.3.0:go_connections/src/github.com/docker/go-connections \
		docker:go-units:v0.3.3:go_units/src/github.com/docker/go-units \
		docker:libnetwork:d7b6174:libnetwork/src/github.com/docker/libnetwork \
		eapache:go-resiliency:v1.1.0:go_resiliency/src/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:040cc1a:go_xerial_snappy/src/github.com/eapache/go-xerial-snappy \
		eapache:queue:v1.1.0:queue/src/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:v1.1.1:paho_mqtt_golang/src/github.com/eclipse/paho.mqtt.golang \
		ericchiang:k8s:v1.2.0:k8s/src/github.com/ericchiang/k8s \
		go-ini:ini:v1.38.1:ini/src/github.com/go-ini/ini \
		go-logfmt:logfmt:v0.3.0:go_logfmt/src/github.com/go-logfmt/logfmt \
		go-ole:go-ole:v1.2.1:go_ole/src/github.com/go-ole/go-ole \
		go-redis:redis:v6.12.0:redis/src/github.com/go-redis/redis \
		go-sql-driver:mysql:v1.4.0:mysql/src/github.com/go-sql-driver/mysql \
		gobwas:glob:v0.2.3:glob/src/github.com/gobwas/glob \
		gogo:protobuf:v1.1.1:gogo_protobuf/src/github.com/gogo/protobuf \
		golang:protobuf:v1.1.0:protobuf/src/github.com/golang/protobuf \
		golang:snappy:2e65f85:snappy/src/github.com/golang/snappy \
		google:go-cmp:v0.2.0:go_cmp/src/github.com/google/go-cmp \
		google:uuid:0.2:uuid/src/github.com/google/uuid \
		googleapis:gax-go:v2.0.0:gax_go/src/github.com/googleapis/gax-go \
		gorilla:context:v1.1.1:context/src/github.com/gorilla/context \
		gorilla:mux:v1.6.2:mux/src/github.com/gorilla/mux \
		hailocab:go-hostpool:e80d13c:go_hostpool/src/github.com/hailocab/go-hostpool \
		hashicorp:consul:v1.2.1:consul/src/github.com/hashicorp/consul \
		hashicorp:go-cleanhttp:d5fe4b5:go_cleanhttp/src/github.com/hashicorp/go-cleanhttp \
		hashicorp:go-rootcerts:6bb64b3:go_rootcerts/src/github.com/hashicorp/go-rootcerts \
		hashicorp:serf:v0.8.1:serf/src/github.com/hashicorp/serf \
		influxdata:go-syslog:v1.0.1:go_syslog/src/github.com/influxdata/go-syslog \
		influxdata:tail:c434825:tail/src/github.com/influxdata/tail \
		influxdata:toml:2a2e301:toml/src/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a:wlog/src/github.com/influxdata/wlog \
		jackc:pgx:v3.1.0:pgx/src/github.com/jackc/pgx \
		jmespath:go-jmespath:0b12d6b:go_jmespath/src/github.com/jmespath/go-jmespath \
		kardianos:osext:ae77be6:osext/src/github.com/kardianos/osext \
		kardianos:service:615a14e:service/src/github.com/kardianos/service \
		kballard:go-shellquote:95032a8:go_shellquote/src/github.com/kballard/go-shellquote \
		kr:logfmt:b84e30a:logfmt/src/github.com/kr/logfmt \
		mailru:easyjson:efc7eb8:easyjson/src/github.com/mailru/easyjson \
		matttproud:golang_protobuf_extensions:v1.0.1:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:v1.0.8:dns/src/github.com/miekg/dns \
		mitchellh:go-homedir:3864e76:go_homedir/src/github.com/mitchellh/go-homedir \
		mitchellh:mapstructure:f15292f:mapstructure/src/github.com/mitchellh/mapstructure \
		multiplay:go-ts3:v1.0.0:go_ts3/src/github.com/multiplay/go-ts3 \
		naoina:go-stringutil:v0.1.0:go_stringutil/src/github.com/naoina/go-stringutil \
		nats-io:gnatsd:v1.2.0:gnatsd/src/github.com/nats-io/gnatsd \
		nats-io:go-nats:v1.5.0:nats/src/github.com/nats-io/go-nats \
		nats-io:nuid:v1.0.0:nuid/src/github.com/nats-io/nuid \
		nsqio:go-nsq:v1.0.7:go_nsq/src/github.com/nsqio/go-nsq \
		opencontainers:go-digest:v1.0.0-rc1:go_digest/src/github.com/opencontainers/go-digest \
		opencontainers:image-spec:v1.0.1:image_spec/src/github.com/opencontainers/image-spec \
		opentracing-contrib:go-observer:a52f234:go_observer/src/github.com/opentracing-contrib/go-observer \
		opentracing:opentracing-go:v1.0.2:opentracing_go/src/github.com/opentracing/opentracing-go \
		openzipkin:zipkin-go-opentracing:v0.3.4:zipkin_go_opentracing/src/github.com/openzipkin/zipkin-go-opentracing \
		pierrec:lz4:v2.0.3:lz4/src/github.com/pierrec/lz4 \
		pkg:errors:v0.8.0:errors/src/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:go_difflib/src/github.com/pmezard/go-difflib \
		prometheus:client_golang:v0.8.0:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:5c3871d:client_model/src/github.com/prometheus/client_model \
		prometheus:common:7600349:common/src/github.com/prometheus/common \
		prometheus:procfs:ae68e2d:procfs/src/github.com/prometheus/procfs \
		rcrowley:go-metrics:e2704e1:go_metrics/src/github.com/rcrowley/go-metrics \
		samuel:go-zookeeper:c4fab1a:go_zookeeper/src/github.com/samuel/go-zookeeper \
		satori:go.uuid:v1.2.0:go_uuid/src/github.com/satori/go.uuid \
		shirou:gopsutil:v2.18.07:gopsutil/src/github.com/shirou/gopsutil \
		shirou:w32:bb4de01:w32/src/github.com/shirou/w32 \
		sirupsen:logrus:v1.0.5:logrus/src/github.com/sirupsen/logrus \
		soniah:gosnmp:96b8622:gosnmp/src/github.com/soniah/gosnmp \
		streadway:amqp:e5adc2a:amqp/src/github.com/streadway/amqp \
		stretchr:objx:v0.1.1:objx/src/github.com/stretchr/objx \
		stretchr:testify:v1.2.2:testify/src/github.com/stretchr/testify \
		tidwall:gjson:v1.1.2:gjson/src/github.com/tidwall/gjson \
		tidwall:match:1731857:match/src/github.com/tidwall/match \
		vishvananda:netlink:b2de5d1:netlink/src/github.com/vishvananda/netlink \
		vishvananda:netns:13995c7:netns/src/github.com/vishvananda/netns \
		vjeantet:grok:v1.0.0:grok/src/github.com/vjeantet/grok \
		vmware:govmomi:v0.18.0:govmomi/src/github.com/vmware/govmomi \
		wvanbergen:kafka:e2edea9:kafka/src/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:f72d861:kazoo_go/src/github.com/wvanbergen/kazoo-go \
		yuin:gopher-lua:46796da:gopher_lua/src/github.com/yuin/gopher-lua \
		census-instrumentation:opencensus-go:v0.17.0:opencensus_go/src/go.opencensus.io \
		googleapis:google-api-go-client:19ff876:api/src/google.golang.org/api \
		golang:crypto:a214413:crypto/src/golang.org/x/crypto \
		golang:net:a680a1e:net/src/golang.org/x/net \
		golang:oauth2:d2e6202:oauth2/src/golang.org/x/oauth2 \
		golang:sys:ac767d6:sys/src/golang.org/x/sys \
		golang:text:v0.3.0:text/src/golang.org/x/text \
		golang:appengine:v1.1.0:appengine/src/google.golang.org/appengine \
		google:go-genproto:fedd286:genproto/src/google.golang.org/genproto \
		grpc:grpc-go:v1.13.0:grpc/src/google.golang.org/grpc \
		alecthomas:kingpin:v2.2.6:kingpin_v2/src/gopkg.in/alecthomas/kingpin.v2 \
		go-asn1-ber:asn1-ber:v1.2:asn1_ber_v1/src/gopkg.in/asn1-ber.v1 \
		fatih:pool:v2.0.0:pool_v2/src/gopkg.in/fatih/pool.v2 \
		fsnotify:fsnotify:v1.4.7:fsnotify_v1/src/gopkg.in/fsnotify.v1 \
		rethinkdb:rethinkdb-go:v3.0.5:gorethink_v3/src/gopkg.in/gorethink/gorethink.v3 \
		go-ldap:ldap:v2.5.1:ldap_v2/src/gopkg.in/ldap.v2 \
		go-mgo:mgo:9856a29:mgo_v2/src/gopkg.in/mgo.v2 \
		olivere:elastic:v5.0.70:elastic_v5/src/gopkg.in/olivere/elastic.v5 \
		go-tomb:tomb:dd63297:tomb_v1/src/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.1:yaml_v2/src/gopkg.in/yaml.v2

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

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./cmd/telegraf

do-install:
	${MKDIR} ${STAGEDIR}${TELEGRAF_LOGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/${GH_SUBDIR}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
