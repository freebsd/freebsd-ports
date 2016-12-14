# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
DISTVERSION=	1.1.2
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	amd64

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	Shopify:sarama:8aadb47:sarama/src/github.com/Shopify/sarama \
		Sirupsen:logrus:219c8cb:logrus/src/github.com/Sirupsen/logrus \
		aerospike:aerospike-client-go:7f3a312:aerospike_client_go/src/github.com/aerospike/aerospike-client-go \
		amir:raidman:53c1b96:raidman/src/github.com/amir/raidman \
		aws:aws-sdk-go:13a1206:aws_sdk_go/src/github.com/aws/aws-sdk-go \
		beorn7:perks:3ac7bf7:perks/src/github.com/beorn7/perks \
		cenkalti:backoff:4dc7767:backoff/src/github.com/cenkalti/backoff \
		couchbase:go-couchbase:cb66431:go_couchbase/src/github.com/couchbase/go-couchbase \
		couchbase:gomemcached:a5ea635:gomemcached/src/github.com/couchbase/gomemcached \
		couchbase:goutils:5823a0c:goutils/src/github.com/couchbase/goutils \
		dancannon:gorethink:e7cac92:gorethink/src/github.com/dancannon/gorethink \
		davecgh:go-spew:5215b55:go_spew/src/github.com/davecgh/go-spew \
		docker:engine-api:8924d69:engine_api/src/github.com/docker/engine-api \
		docker:go-connections:f549a93:go_connections/src/github.com/docker/go-connections \
		docker:go-units:5d2041e:go_units/src/github.com/docker/go-units \
		eapache:go-resiliency:b86b1ec:go_resiliency/src/github.com/eapache/go-resiliency \
		eapache:queue:ded5959:queue/src/github.com/eapache/queue \
		eclipse:paho.mqtt.golang:0f7a459:paho_mqtt_golang/src/github.com/eclipse/paho.mqtt.golang \
		go-sql-driver:mysql:1fca743:mysql/src/github.com/go-sql-driver/mysql \
		gobwas:glob:49571a1:glob/src/github.com/gobwas/glob \
		golang:protobuf:552c7b9:protobuf/src/github.com/golang/protobuf \
		golang:snappy:d9eb7a3:snappy/src/github.com/golang/snappy \
		gonuts:go-shellquote:e842a11:go_shellquote/src/github.com/gonuts/go-shellquote \
		gorilla:context:1ea2538:context/src/github.com/gorilla/context \
		gorilla:mux:c9e326e:mux/src/github.com/gorilla/mux \
		hailocab:go-hostpool:e80d13c:go_hostpool/src/github.com/hailocab/go-hostpool \
		hashicorp:consul:5aa9045:consul/src/github.com/hashicorp/consul \
		hpcloud:tail:b294095:tail/src/github.com/hpcloud/tail \
		influxdata:config:b79f682:config/src/github.com/influxdata/config \
		influxdata:influxdb:fc57c0f:influxdb/src/github.com/influxdata/influxdb \
		influxdata:toml:af4df43:toml/src/github.com/influxdata/toml \
		influxdata:wlog:7c63b0a:wlog/src/github.com/influxdata/wlog \
		kardianos:osext:29ae4ff:osext/src/github.com/kardianos/osext \
		kardianos:service:5e33559:service/src/github.com/kardianos/service \
		klauspost:crc32:19b0b33:crc32/src/github.com/klauspost/crc32 \
		lib:pq:e182dc4:pq/src/github.com/lib/pq \
		matttproud:golang_protobuf_extensions:d0c3fe8:golang_protobuf_extensions/src/github.com/matttproud/golang_protobuf_extensions \
		miekg:dns:cce6c13:dns/src/github.com/miekg/dns \
		mreiferson:go-snappystream:028eae7:go_snappystream/src/github.com/mreiferson/go-snappystream \
		naoina:go-stringutil:6b638e9:go_stringutil/src/github.com/naoina/go-stringutil \
		nats-io:go-nats:ea8b4fd:go_nats/src/github.com/nats-io/nats \
		nats-io:nuid:a5152d6:nuid/src/github.com/nats-io/nuid \
		nsqio:go-nsq:0b80d6f:go_nsq/src/github.com/nsqio/go-nsq \
		opencontainers:runc:89ab7f2:runc/src/github.com/opencontainers/runc \
		prometheus:client_golang:18acf99:client_golang/src/github.com/prometheus/client_golang \
		prometheus:client_model:fa8ad6f:client_model/src/github.com/prometheus/client_model \
		prometheus:common:e8eabff:common/src/github.com/prometheus/common \
		prometheus:procfs:406e5b7:procfs/src/github.com/prometheus/procfs \
		samuel:go-zookeeper:218e9c8:go_zookeeper/src/github.com/samuel/go-zookeeper \
		shirou:gopsutil:4d0c402:gopsutil/src/github.com/shirou/gopsutil \
		soniah:gosnmp:3fe3beb:gosnmp/src/github.com/soniah/gosnmp \
		sparrc:gdm:66023a5:gdm/src/github.com/sparrc/gdm \
		streadway:amqp:b4f3cea:amqp/src/github.com/streadway/amqp \
		stretchr:testify:1f4a164:testify/src/github.com/stretchr/testify \
		vjeantet:grok:83bfdfd:grok/src/github.com/vjeantet/grok \
		wvanbergen:kafka:46f9a1c:kafka/src/github.com/wvanbergen/kafka \
		wvanbergen:kazoo-go:0f76871:kazoo_go/src/github.com/wvanbergen/kazoo-go \
		yuin:gopher-lua:bf3808a:gopher_lua/src/github.com/yuin/gopher-lua \
		zensqlmonitor:go-mssqldb:ffe5510:go_mssqldb/src/github.com/zensqlmonitor/go-mssqldb \
		golang:crypto:c197bcf:crypto/src/golang.org/x/crypto \
		golang:net:6acef71:net/src/golang.org/x/net \
		golang:text:a71fd10:text/src/golang.org/x/text \
		golang:tools:fc2b74b:tools/src/golang.org/x/tools \
		dancannon:gorethink:7d1af5b:gorethink_v1/src/gopkg.in/dancannon/gorethink.v1 \
		fatih:pool:cba550e:pool_v2/src/gopkg.in/fatih/pool.v2 \
		go-mgo:mgo:d90005c:mgo/src/gopkg.in/mgo.v2 \
		go-yaml:yaml:a83829b:yaml/src/gopkg.in/yaml.v2

SUB_FILES=	telegraf
SUB_LIST+=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}
PLIST_SUB=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}
	@cd ${WRKSRC} && ${MV} CHANGELOG.md CONTRIBUTING.md Godeps Godeps_windows \
		LICENSE Makefile README.md accumulator.go agent aggregator.go circle.yml cmd docs etc filter \
		input.go internal logger metric.go metric_test.go output.go plugins processor.go scripts testutil \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} && \
		${SETENV} GOPATH=${WRKSRC} go install -ldflags "-X main.version=${DISTVERSION}" ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT_DEFAULT}/${GH_PROJECT}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
