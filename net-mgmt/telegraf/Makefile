# Created by: Stefan Lambrev <cheffo@freebsd-bg.org>
# $FreeBSD$

PORTNAME=	telegraf
PORTVERSION=	1.0.0.b3
CATEGORIES=	net-mgmt

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	Time-series data collection

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.5.0:lang/go

ONLY_FOR_ARCHS=	amd64

USE_RC_SUBR=	telegraf

USE_GITHUB=	yes

GH_TAGNAME=	1.0.0-beta3
GH_ACCOUNT=	influxdata:DEFAULT
GH_TUPLE=	Shopify:sarama:9bb4a68:sarama \
		Sirupsen:logrus:a283a10:logrus \
		aerospike:aerospike-client-go:11f20fc:aerospike_client_go \
		amir:raidman:c74861f:raidman \
		aws:aws-sdk-go:5f1600d:aws_sdk_go \
		beorn7:perks:4c0e845:perks \
		cenkalti:backoff:cdf48bb:backoff \
		couchbase:go-couchbase:264eacd:go_couchbase \
		couchbase:gomemcached:6172a8c:gomemcached \
		couchbase:goutils:5823a0c:goutils \
		davecgh:go-spew:5215b55:go_spew \
		docker:distribution:bfa0a9c:distribution \
		docker:engine-api:16c66e8:engine_api \
		docker:go-connections:990a1a1:go_connections \
		docker:go-units:eb879ae:go_units \
		eapache:go-resiliency:b86b1ec:go_resiliency \
		eapache:go-xerial-snappy:bb955e0:go_xerial_snappy \
		eapache:queue:44cc805:queue \
		eclipse:paho.mqtt.golang:44eec14:paho_mqtt_golang \
		go-sql-driver:mysql:0b58b37:mysql \
		gobwas:glob:ce6abff:glob \
		golang:protobuf:c3cefd4:protobuf \
		golang:snappy:d9eb7a3:snappy \
		gonuts:go-shellquote:e842a11:go_shellquote \
		gorilla:context:aed02d1:context \
		gorilla:mux:7804150:mux \
		hailocab:go-hostpool:e80d13c:go_hostpool \
		hashicorp:consul:4d73872:consul \
		hpcloud:tail:a30252c:tail \
		influxdata:config:8ec4638:config \
		influxdata:influxdb:a62fbcd:influxdb \
		influxdata:toml:ff2a260:toml \
		klauspost:crc32:19b0b33:crc32 \
		lib:pq:4dd446e:pq \
		matttproud:golang_protobuf_extensions:c12348c:golang_protobuf_extensions \
		miekg:dns:db96a2b:dns \
		mreiferson:go-snappystream:028eae7:go_snappystream \
		naoina:go-stringutil:6b638e9:go_stringutil \
		nats-io:nats:aea6480:nats \
		nats-io:nuid:a5152d6:nuid \
		nsqio:go-nsq:d71fb89:go_nsq \
		opencontainers:runc:142df38:runc \
		prometheus:client_golang:52437c8:client_golang \
		prometheus:client_model:fa8ad6f:client_model \
		prometheus:common:ebdfc6d:common \
		prometheus:procfs:abf152e:procfs \
		samuel:go-zookeeper:e64db45:go_zookeeper \
		shirou:gopsutil:4d0c402:gopsutil \
		soniah:gosnmp:29f8b35:gosnmp \
		streadway:amqp:2e25825:amqp \
		stretchr:testify:d77da35:testify \
		vjeantet:grok:83bfdfd:grok \
		wvanbergen:kafka:6df90f1:kafka \
		wvanbergen:kazoo-go:0f76871:kazoo_go \
		yuin:gopher-lua:e57b640:gopher_lua \
		zensqlmonitor:go-mssqldb:ffe5510:go_mssqldb \
		golang:crypto:7a1054f:crypto \
		golang:net:7c62cfd:net \
		golang:text:2910a50:text \
		dancannon:gorethink:edc7a6a:gorethink_v1 \
		fatih:pool:20a0a42:pool_v2 \
		go-mgo:mgo:0108465:mgo \
		go-yaml:yaml:e4d366f:yaml

SUB_FILES=	telegraf
SUB_LIST+=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}
PLIST_SUB=	TELEGRAF_PIDDIR=${TELEGRAF_PIDDIR}

STRIP=		# stripping can break go binaries

post-patch:
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME} \
	${WRKSRC}/src/git.eclipse.org/gitroot \
	${WRKSRC}/src/github.com/Shopify \
	${WRKSRC}/src/github.com/Sirupsen \
	${WRKSRC}/src/github.com/aerospike \
	${WRKSRC}/src/github.com/amir \
	${WRKSRC}/src/github.com/aws \
	${WRKSRC}/src/github.com/beorn7 \
	${WRKSRC}/src/github.com/cenkalti \
	${WRKSRC}/src/github.com/couchbase \
	${WRKSRC}/src/github.com/dancannon \
	${WRKSRC}/src/github.com/davecgh \
	${WRKSRC}/src/github.com/docker \
	${WRKSRC}/src/github.com/eapache \
	${WRKSRC}/src/github.com/eclipse \
	${WRKSRC}/src/github.com/fsouza \
	${WRKSRC}/src/github.com/go-sql-driver \
	${WRKSRC}/src/github.com/gobwas \
	${WRKSRC}/src/github.com/golang \
	${WRKSRC}/src/github.com/gonuts \
	${WRKSRC}/src/github.com/gorilla \
	${WRKSRC}/src/github.com/hailocab \
	${WRKSRC}/src/github.com/hashicorp \
	${WRKSRC}/src/github.com/hpcloud \
	${WRKSRC}/src/github.com/influxdata \
	${WRKSRC}/src/github.com/klauspost \
	${WRKSRC}/src/github.com/lib \
	${WRKSRC}/src/github.com/matttproud \
	${WRKSRC}/src/github.com/miekg \
	${WRKSRC}/src/github.com/mreiferson \
	${WRKSRC}/src/github.com/naoina \
	${WRKSRC}/src/github.com/nats-io \
	${WRKSRC}/src/github.com/nsqio \
	${WRKSRC}/src/github.com/opencontainers \
	${WRKSRC}/src/github.com/prometheus \
	${WRKSRC}/src/github.com/samuel \
	${WRKSRC}/src/github.com/shirou \
	${WRKSRC}/src/github.com/soniah \
	${WRKSRC}/src/github.com/sparrc \
	${WRKSRC}/src/github.com/streadway \
	${WRKSRC}/src/github.com/stretchr \
	${WRKSRC}/src/github.com/vjeantet \
	${WRKSRC}/src/github.com/wvanbergen \
	${WRKSRC}/src/github.com/yuin \
	${WRKSRC}/src/github.com/zensqlmonitor \
	${WRKSRC}/src/golang.org/x \
	${WRKSRC}/src/gopkg.in/dancannon \
	${WRKSRC}/src/gopkg.in/fatih
	cd ${WRKSRC} && ${MV} CHANGELOG.md CONTRIBUTING.md Godeps Godeps_windows \
		LICENSE Makefile README.md accumulator.go agent circle.yml cmd docs etc filter \
		input.go internal metric.go metric_test.go output.go plugins scripts testutil \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
	@${LN} -s ${WRKSRC}/src/github.com/eclipse/paho.mqtt.golang ${WRKSRC}/src/git.eclipse.org/gitroot/paho
	@${LN} -s ${WRKSRC}/src/github.com/aerospike/aerospike-client-go ${WRKSRC}/src/github.com/sparrc/aerospike-client-go
	@${MV} ${WRKSRC_sarama} ${WRKSRC}/src/github.com/Shopify/sarama ;\
	${MV} ${WRKSRC_logrus} ${WRKSRC}/src/github.com/Sirupsen/logrus ;\
	${MV} ${WRKSRC_aerospike_client_go} ${WRKSRC}/src/github.com/aerospike/aerospike-client-go ;\
	${MV} ${WRKSRC_raidman} ${WRKSRC}/src/github.com/amir/raidman ;\
	${MV} ${WRKSRC_aws_sdk_go} ${WRKSRC}/src/github.com/aws/aws-sdk-go ;\
	${MV} ${WRKSRC_perks} ${WRKSRC}/src/github.com/beorn7/perks ;\
	${MV} ${WRKSRC_backoff} ${WRKSRC}/src/github.com/cenkalti/backoff ;\
	${MV} ${WRKSRC_go_couchbase} ${WRKSRC}/src/github.com/couchbase/go-couchbase ;\
	${MV} ${WRKSRC_gomemcached} ${WRKSRC}/src/github.com/couchbase/gomemcached ;\
	${MV} ${WRKSRC_goutils} ${WRKSRC}/src/github.com/couchbase/goutils ;\
	${MV} ${WRKSRC_go_spew} ${WRKSRC}/src/github.com/davecgh/go-spew ;\
	${MV} ${WRKSRC_distribution} ${WRKSRC}/src/github.com/docker/distribution ;\
	${MV} ${WRKSRC_engine_api} ${WRKSRC}/src/github.com/docker/engine-api ;\
	${MV} ${WRKSRC_go_connections} ${WRKSRC}/src/github.com/docker/go-connections ;\
	${MV} ${WRKSRC_go_units} ${WRKSRC}/src/github.com/docker/go-units ;\
	${MV} ${WRKSRC_go_resiliency} ${WRKSRC}/src/github.com/eapache/go-resiliency ;\
	${MV} ${WRKSRC_go_xerial_snappy} ${WRKSRC}/src/github.com/eapache/go-xerial-snappy ;\
	${MV} ${WRKSRC_queue} ${WRKSRC}/src/github.com/eapache/queue ;\
	${MV} ${WRKSRC_paho_mqtt_golang} ${WRKSRC}/src/github.com/eclipse/paho.mqtt.golang ;\
	${MV} ${WRKSRC_mysql} ${WRKSRC}/src/github.com/go-sql-driver/mysql ;\
	${MV} ${WRKSRC_glob} ${WRKSRC}/src/github.com/gobwas/glob ;\
	${MV} ${WRKSRC_protobuf} ${WRKSRC}/src/github.com/golang/protobuf ;\
	${MV} ${WRKSRC_snappy} ${WRKSRC}/src/github.com/golang/snappy ;\
	${MV} ${WRKSRC_go_shellquote} ${WRKSRC}/src/github.com/gonuts/go-shellquote ;\
	${MV} ${WRKSRC_context} ${WRKSRC}/src/github.com/gorilla/context ;\
	${MV} ${WRKSRC_mux} ${WRKSRC}/src/github.com/gorilla/mux ;\
	${MV} ${WRKSRC_go_hostpool} ${WRKSRC}/src/github.com/hailocab/go-hostpool ;\
	${MV} ${WRKSRC_consul} ${WRKSRC}/src/github.com/hashicorp/consul ;\
	${MV} ${WRKSRC_tail} ${WRKSRC}/src/github.com/hpcloud/tail ;\
	${MV} ${WRKSRC_config} ${WRKSRC}/src/github.com/influxdata/config ;\
	${MV} ${WRKSRC_influxdb} ${WRKSRC}/src/github.com/influxdata/influxdb ;\
	${MV} ${WRKSRC_toml} ${WRKSRC}/src/github.com/influxdata/toml ;\
	${MV} ${WRKSRC_crc32} ${WRKSRC}/src/github.com/klauspost/crc32 ;\
	${MV} ${WRKSRC_pq} ${WRKSRC}/src/github.com/lib/pq ;\
	${MV} ${WRKSRC_golang_protobuf_extensions} ${WRKSRC}/src/github.com/matttproud/golang_protobuf_extensions ;\
	${MV} ${WRKSRC_dns} ${WRKSRC}/src/github.com/miekg/dns ;\
	${MV} ${WRKSRC_go_snappystream} ${WRKSRC}/src/github.com/mreiferson/go-snappystream ;\
	${MV} ${WRKSRC_go_stringutil} ${WRKSRC}/src/github.com/naoina/go-stringutil ;\
	${MV} ${WRKSRC_nats} ${WRKSRC}/src/github.com/nats-io/nats ;\
	${MV} ${WRKSRC_nuid} ${WRKSRC}/src/github.com/nats-io/nuid ;\
	${MV} ${WRKSRC_go_nsq} ${WRKSRC}/src/github.com/nsqio/go-nsq ;\
	${MV} ${WRKSRC_runc} ${WRKSRC}/src/github.com/opencontainers/runc ;\
	${MV} ${WRKSRC_client_golang} ${WRKSRC}/src/github.com/prometheus/client_golang ;\
	${MV} ${WRKSRC_client_model} ${WRKSRC}/src/github.com/prometheus/client_model ;\
	${MV} ${WRKSRC_common} ${WRKSRC}/src/github.com/prometheus/common ;\
	${MV} ${WRKSRC_procfs} ${WRKSRC}/src/github.com/prometheus/procfs ;\
	${MV} ${WRKSRC_go_zookeeper} ${WRKSRC}/src/github.com/samuel/go-zookeeper ;\
	${MV} ${WRKSRC_gopsutil} ${WRKSRC}/src/github.com/shirou/gopsutil ;\
	${MV} ${WRKSRC_gosnmp} ${WRKSRC}/src/github.com/soniah/gosnmp ;\
	${MV} ${WRKSRC_amqp} ${WRKSRC}/src/github.com/streadway/amqp ;\
	${MV} ${WRKSRC_testify} ${WRKSRC}/src/github.com/stretchr/testify ;\
	${MV} ${WRKSRC_grok} ${WRKSRC}/src/github.com/vjeantet/grok ;\
	${MV} ${WRKSRC_kafka} ${WRKSRC}/src/github.com/wvanbergen/kafka ;\
	${MV} ${WRKSRC_kazoo_go} ${WRKSRC}/src/github.com/wvanbergen/kazoo-go ;\
	${MV} ${WRKSRC_gopher_lua} ${WRKSRC}/src/github.com/yuin/gopher-lua ;\
	${MV} ${WRKSRC_go_mssqldb} ${WRKSRC}/src/github.com/zensqlmonitor/go-mssqldb ;\
	${MV} ${WRKSRC_crypto} ${WRKSRC}/src/golang.org/x/crypto ;\
	${MV} ${WRKSRC_net} ${WRKSRC}/src/golang.org/x/net ;\
	${MV} ${WRKSRC_text} ${WRKSRC}/src/golang.org/x/text ;\
	${MV} ${WRKSRC_gorethink_v1} ${WRKSRC}/src/gopkg.in/dancannon/gorethink.v1 ;\
	${MV} ${WRKSRC_pool_v2} ${WRKSRC}/src/gopkg.in/fatih/pool.v2 ;\
	${MV} ${WRKSRC_mgo} ${WRKSRC}/src/gopkg.in/mgo.v2 ;\
	${MV} ${WRKSRC_yaml} ${WRKSRC}/src/gopkg.in/yaml.v2

do-build:
	@cd ${WRKSRC}/src/github.com/influxdata/${PORTNAME} && ${SETENV} GOPATH=${WRKSRC} go install ./...

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${GH_PROJECT}/etc/${PORTNAME}.conf  \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
