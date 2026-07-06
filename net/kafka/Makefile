PORTNAME=	kafka
DISTVERSION=	4.3.0
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${DISTVERSION}/
DISTNAME=	${PORTNAME}_2.13-${DISTVERSION}

MAINTAINER=	timp87@gmail.com
COMMENT=	Distributed streaming platform
WWW=		https://kafka.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cpe java shebangfix tar:tgz
CPE_VENDOR=	apache
JAVA_VERSION=	17+

USE_RC_SUBR=	kafka kafka_connect

SHEBANG_FILES=	bin/*.sh

KAFKA_USER?=	${PORTNAME}
KAFKA_GROUP?=	${PORTNAME}
KAFKA_DBDIR?=	/var/db/${PORTNAME}
KAFKA_LOGDIR?=	/var/log/${PORTNAME}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_LIST=	KAFKA_DBDIR=${KAFKA_DBDIR} \
		KAFKA_GROUP=${KAFKA_GROUP} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR} \
		KAFKA_USER=${KAFKA_USER}
.if ${KAFKA_USER} == ${PORTNAME}
USERS=		${KAFKA_USER}
.endif
.if ${KAFKA_GROUP} == ${PORTNAME}
GROUPS=		${KAFKA_GROUP}
.endif

KAFKA_BINS=	connect-distributed.sh connect-mirror-maker.sh \
		connect-plugin-path.sh connect-standalone.sh kafka-acls.sh \
		kafka-broker-api-versions.sh kafka-client-metrics.sh \
		kafka-cluster.sh kafka-configs.sh kafka-console-consumer.sh \
		kafka-console-producer.sh kafka-console-share-consumer.sh \
		kafka-consumer-groups.sh kafka-consumer-perf-test.sh \
		kafka-delegation-tokens.sh kafka-delete-records.sh \
		kafka-dump-log.sh kafka-e2e-latency.sh kafka-features.sh \
		kafka-get-offsets.sh kafka-groups.sh kafka-jmx.sh \
		kafka-leader-election.sh kafka-log-dirs.sh \
		kafka-metadata-quorum.sh kafka-metadata-shell.sh \
		kafka-producer-perf-test.sh kafka-reassign-partitions.sh \
		kafka-replica-verification.sh kafka-run-class.sh \
		kafka-server-start.sh kafka-server-stop.sh \
		kafka-share-consumer-perf-test.sh kafka-share-groups.sh \
		kafka-storage.sh kafka-streams-application-reset.sh \
		kafka-streams-groups.sh kafka-topics.sh kafka-transactions.sh \
		kafka-verifiable-consumer.sh kafka-verifiable-producer.sh \
		kafka-verifiable-share-consumer.sh trogdor.sh
KAFKA_CONFIGS=	broker.properties controller.properties \
		connect-console-sink.properties \
		connect-console-source.properties \
		connect-distributed.properties connect-file-sink.properties \
		connect-file-source.properties connect-log4j2.yaml \
		connect-mirror-maker.properties connect-standalone.properties \
		consumer.properties log4j2.yaml producer.properties \
		server.properties tools-log4j2.yaml trogdor.conf

PLIST_SUB=	KAFKA_DBDIR=${KAFKA_DBDIR} \
		KAFKA_GROUP=${KAFKA_GROUP} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR} \
		KAFKA_USER=${KAFKA_USER} \
		DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s|JAVA=\"java\"|JAVA=\"${LOCALBASE}/bin/java\"|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "/LOG_DIR=/s|\$$base_dir/logs|${KAFKA_LOGDIR}|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "s|\$$base_dir.*/config|${ETCDIR}|" \
		${WRKSRC}/bin/kafka-run-class.sh \
		${WRKSRC}/bin/kafka-server-start.sh \
		${WRKSRC}/bin/connect-mirror-maker.sh \
		${WRKSRC}/bin/connect-distributed.sh \
		${WRKSRC}/bin/connect-standalone.sh
	@${REINPLACE_CMD} "s|ps ax|ps axww|" ${WRKSRC}/bin/kafka-server-stop.sh
	@${REINPLACE_CMD} "/log.dirs/s|=.*|=${KAFKA_DBDIR}|" \
		${WRKSRC}/config/server.properties \
		${WRKSRC}/config/broker.properties \
		${WRKSRC}/config/controller.properties
	@${REINPLACE_CMD} "s|#plugin.path=|#plugin.path=${DATADIR}/libs|" \
		${WRKSRC}/config/connect-standalone.properties \
		${WRKSRC}/config/connect-distributed.properties

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${KAFKA_DBDIR} \
		 ${STAGEDIR}${KAFKA_LOGDIR} \
		 ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${KAFKA_BINS:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${DATADIR}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} libs ${STAGEDIR}${DATADIR} "-not ( \
		-name kafka_*-javadoc\.jar -or -name kafka_*-scaladoc\.jar -or \
		-name kafka_*-sources\.jar -or -name kafka_*-test\.jar -or \
		-name *\.asc )" \
	)
.for f in ${KAFKA_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${EXTRACT_CMD} -xf ${WRKSRC}/site-docs/${PORTNAME}_2.13-${DISTVERSION}-site-docs.tgz \
		-C ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
