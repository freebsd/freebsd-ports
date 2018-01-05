# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
DISTVERSION=	1.5.0
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	amd64

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	collectd:go-collectd:2ce1445:collectd_org/src/collectd.org \
		aerospike:aerospike-client-go:95e1ad7:aerospike_client_go/src/github.com/aerospike/aerospike-client-go \
		amir:raidman:c74861f:raidman/src/github.com/amir/raidman \
		apache:thrift:4aaa92ec:thrift/src/github.com/apache/thrift \
		aws:aws-sdk-go:c861d27d:aws_sdk_go/src/github.com/aws/aws-sdk-go \
		beorn7:perks:4c0e845:perks/src/github.com/beorn7/perks \
		bsm:sarama-cluster:abf0394:sarama_cluster/src/github.com/bsm/sarama-cluster \
		cenkalti:backoff:b02f2bb:backoff/src/github.com/cenkalti/backoff \
		couchbase:go-couchbase:bfe555a:go_couchbase/src/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:4a25d2f:gomemcached/src/github.com/couchbase/gomemcached \
		couchbase:goutils:5823a0c:goutils/src/github.com/couchbase/goutils \
		davecgh:go-spew:346938d:go_spew/src/github.com/davecgh/go-spew \
		dgrijalva:jwt-go:dbeaa93:jwt_go/src/github.com/dgrijalva/jwt-go \
		moby:moby:f5ec1e293:docker/src/github.com/docker/docker \
		docker:go-connections:990a1a1:go_connections/src/github.com/docker/go-connections \
		eapache:go-resiliency:b86b1ec:go_resiliency/src/github.com/eapache/go-resiliency \
		eapache:go-xerial-snappy:bb955e0:go_xerial_snappy/src/github.com/eapache/go-xerial-snappy \
		eapache:queue:44cc805:queue/src/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:d4f545e:paho_mqtt_golang/src/github.com/eclipse/paho.mqtt.golang \
		go-ini:ini:9144852:ini/src/github.com/go-ini/ini \
		go-logfmt:logfmt:390ab79:logfmt/src/github.com/go-logfmt/logfmt \
		go-ole:go-ole:be49f7c:go_ole/src/github.com/go-ole/go-ole \
		go-sql-driver:mysql:2e00b5c:mysql/src/github.com/go-sql-driver/mysql \
		gobwas:glob:bea32b9:glob/src/github.com/gobwas/glob \
		gogo:protobuf:7b6c6391:gogo_protobuf/src/github.com/gogo/protobuf \
		golang:protobuf:8ee7999:protobuf/src/github.com/golang/protobuf \
		golang:snappy:7db9049:snappy/src/github.com/golang/snappy \
		google:go-cmp:f94e52c:go_cmp/src/github.com/google/go-cmp \
		gorilla:mux:392c28f:mux/src/github.com/gorilla/mux \
		hailocab:go-hostpool:e80d13c:go_hostpool/src/github.com/hailocab/go-hostpool \
		hashicorp:consul:63d2fc68:consul/src/github.com/hashicorp/consul \
		influxdata:tail:a395bf9:tail/src/github.com/influxdata/tail \
		influxdata:toml:5d1d907:toml/src/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a:wlog/src/github.com/influxdata/wlog \
		jackc:pgx:63f58fd:pgx/src/github.com/jackc/pgx \
		jmespath:go-jmespath:bd40a43:go_jmespath/src/github.com/jmespath/go-jmespath \
		kardianos:osext:c2c54e5:osext/src/github.com/kardianos/osext \
		kardianos:service:6d3a0ee:service/src/github.com/kardianos/service \
		kballard:go-shellquote:d8ec1a6:go_shellquote/src/github.com/kballard/go-shellquote \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		Microsoft:go-winio:ce2922f:go_winio/src/github.com/Microsoft/go-winio \
		miekg:dns:99f84ae:dns/src/github.com/miekg/dns \
		mitchellh:mapstructure:d0303fe:mapstructure/src/github.com/mitchellh/mapstructure \
		multiplay:go-ts3:07477f4:go_ts3/src/github.com/multiplay/go-ts3 \
		naoina:go-stringutil:6b638e9:go_stringutil/src/github.com/naoina/go-stringutil \
		nats-io:go-nats:ea95856:nats/src/github.com/nats-io/nats \
		nats-io:nuid:289cccf:nuid/src/github.com/nats-io/nuid \
		nsqio:go-nsq:eee57a3:go_nsq/src/github.com/nsqio/go-nsq \
		opencontainers:runc:89ab7f2c:runc/src/github.com/opencontainers/runc \
		opentracing:opentracing-go:06f47b4:opentracing_go/src/github.com/opentracing/opentracing-go \
		opentracing-contrib:go-observer:a52f234:go_observer/src/github.com/opentracing-contrib/go-observer \
		openzipkin:zipkin-go-opentracing:1cafbdf:zipkin_go_opentracing/src/github.com/openzipkin/zipkin-go-opentracing \
		pierrec:lz4:5c9560b:lz4/src/github.com/pierrec/lz4 \
		pierrec:xxHash:5a00444:xxHash/src/github.com/pierrec/xxHash \
		pkg:errors:645ef00:errors/src/github.com/pkg/errors \
		pmezard:go-difflib:792786c:go_difflib/src/github.com/pmezard/go-difflib \
		prometheus:client_golang:c317fb7:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:fa8ad6f:client_model/src/github.com/prometheus/client_model \
		prometheus:common:dd2f054:common/src/github.com/prometheus/common \
		prometheus:procfs:1878d9f:procfs/src/github.com/prometheus/procfs \
		rcrowley:go-metrics:1f30fe9:go_metrics/src/github.com/rcrowley/go-metrics \
		samuel:go-zookeeper:1d7be4e:go_zookeeper/src/github.com/samuel/go-zookeeper \
		satori:go.uuid:5bf94b6:go_uuid/src/github.com/satori/go.uuid \
		shirou:gopsutil:384a551:gopsutil/src/github.com/shirou/gopsutil \
		shirou:w32:3c9377f:w32/src/github.com/shirou/w32 \
		Shopify:sarama:3b1b388:sarama/src/github.com/Shopify/sarama \
		Sirupsen:logrus:61e43dc:logrus/src/github.com/Sirupsen/logrus \
		soniah:gosnmp:5ad50dc:gosnmp/src/github.com/soniah/gosnmp \
		sparrc:gdm:81089da:gdm/src/github.com/sparrc/gdm \
		StackExchange:wmi:f3e2bae:wmi/src/github.com/StackExchange/wmi \
		streadway:amqp:63795da:amqp/src/github.com/streadway/amqp \
		stretchr:objx:1a9d0bb:objx/src/github.com/stretchr/objx \
		stretchr:testify:4d4bfba:testify/src/github.com/stretchr/testify \
		vjeantet:grok:d73e972:grok/src/github.com/vjeantet/grok \
		wvanbergen:kafka:bc265fe:kafka/src/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:9689573:kazoo_go/src/github.com/wvanbergen/kazoo-go \
		yuin:gopher-lua:66c871e:gopher_lua/src/github.com/yuin/gopher-lua \
		zensqlmonitor:go-mssqldb:ffe5510:go_mssqldb/src/github.com/zensqlmonitor/go-mssqldb \
		golang:crypto:dc137be:crypto/src/golang.org/x/crypto \
		golang:net:f249948:net/src/golang.org/x/net \
		golang:sys:7397344:sys/src/golang.org/x/sys \
		golang:text:506f9d5:text/src/golang.org/x/text \
		golang:tools:b790d0ba:tools/src/golang.org/x/tools \
		fatih:pool:6e328e6:pool_v2/src/gopkg.in/fatih/pool.v2 \
		go-fsnotify:fsnotify:a8a77c9:fsnotify/src/gopkg.in/fsnotify.v1/fsnotify \
		gorethink:gorethink:7ab832f:gorethink_v3/src/gopkg.in/gorethink/gorethink.v3 \
		go-asn1-ber:asn1-ber:4e86f43:asn1_ber/src/gopkg.in/asn1-ber.v1 \
		go-ldap:ldap:8168ee0:ldap/src/gopkg.in/ldap.v2 \
		go-mgo:mgo:3f83fa5:mgo/src/gopkg.in/mgo.v2 \
		olivere:elastic:3113f9b:elastic_v5/src/gopkg.in/olivere/elastic.v5 \
		go-tomb:tomb:dd63297:tomb/src/gopkg.in/tomb.v1 \
		go-yaml:yaml:4c78c97:yaml/src/gopkg.in/yaml.v2

SUB_FILES=	telegraf
SUB_LIST+=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}
PLIST_SUB=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	@cd ${WRKSRC} && ${MV} appveyor.yml CHANGELOG.md CONTRIBUTING.md Godeps \
		LICENSE Makefile README.md accumulator.go agent aggregator.go circle.yml cmd docs etc filter \
		input.go internal logger metric metric.go output.go plugins processor.go scripts selfstat testutil \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	${LN} -s nats ${WRKSRC}/src/github.com/nats-io/go-nats

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} && \
		${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
