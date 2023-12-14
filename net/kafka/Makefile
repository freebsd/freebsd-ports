PORTNAME=	kafka
DISTVERSION=	3.6.1
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}_2.13-${PORTVERSION}

MAINTAINER=	timp87@gmail.com
COMMENT=	Distributed streaming platform
WWW=		https://kafka.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cpe shebangfix tar:tgz
CPE_VENDOR=	apache

USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_RUN=	jre

USE_RC_SUBR=	kafka kafka_connect

SHEBANG_FILES=	bin/*.sh

KAFKA_USER?=	kafka
KAFKA_GROUP?=	kafka
KAFKA_DBDIR?=	/var/db/${PORTNAME}
KAFKA_DBDIR_KRAFT?=	${KAFKA_DBDIR}-kraft
KAFKA_LOGDIR?=	/var/log/${PORTNAME}

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	JAVA=${JAVA} \
		KAFKA_USER=${KAFKA_USER} \
		KAFKA_GROUP=${KAFKA_GROUP} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR} \
		KAFKA_DBDIR=${KAFKA_DBDIR} \
		KAFKA_DBDIR_KRAFT=${KAFKA_DBDIR_KRAFT}
USERS=		${KAFKA_USER}
GROUPS=		${KAFKA_GROUP}

KAFKA_BINS=	connect-distributed.sh connect-mirror-maker.sh \
		connect-plugin-path.sh connect-standalone.sh kafka-acls.sh \
		kafka-broker-api-versions.sh kafka-cluster.sh kafka-configs.sh \
		kafka-console-consumer.sh kafka-console-producer.sh \
		kafka-consumer-groups.sh kafka-consumer-perf-test.sh \
		kafka-delegation-tokens.sh kafka-delete-records.sh \
		kafka-dump-log.sh kafka-e2e-latency.sh kafka-features.sh \
		kafka-get-offsets.sh kafka-jmx.sh \
		kafka-leader-election.sh kafka-log-dirs.sh \
		kafka-metadata-quorum.sh kafka-metadata-shell.sh \
		kafka-mirror-maker.sh kafka-producer-perf-test.sh \
		kafka-reassign-partitions.sh kafka-replica-verification.sh \
		kafka-run-class.sh kafka-server-start.sh kafka-server-stop.sh \
		kafka-storage.sh kafka-streams-application-reset.sh \
		kafka-topics.sh kafka-transactions.sh \
		kafka-verifiable-consumer.sh kafka-verifiable-producer.sh \
		trogdor.sh zookeeper-security-migration.sh zookeeper-shell.sh
KAFKA_CONFIGS=	connect-console-sink.properties \
		connect-console-source.properties \
		connect-distributed.properties connect-file-sink.properties \
		connect-file-source.properties connect-log4j.properties \
		connect-mirror-maker.properties connect-standalone.properties \
		consumer.properties log4j.properties producer.properties \
		server.properties tools-log4j.properties trogdor.conf
KAFKA_CONFIGS_KRAFT=	broker.properties controller.properties server.properties

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		KAFKA_USER=${KAFKA_USER} \
		KAFKA_GROUP=${KAFKA_GROUP} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR} \
		KAFKA_DBDIR=${KAFKA_DBDIR} \
		KAFKA_DBDIR_KRAFT=${KAFKA_DBDIR_KRAFT}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} "s|JAVA=\"java\"|JAVA=\"${JAVA}\"|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "/LOG_DIR=/s|\$$base_dir/logs|${KAFKA_LOGDIR}|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "s|\$$base_dir.*/config|${ETCDIR}|" ${WRKSRC}/bin/*.sh
	@${REINPLACE_CMD} "s|ps ax|ps axww|" ${WRKSRC}/bin/kafka-server-stop.sh
	@${REINPLACE_CMD} "/log.dirs/s|=.*|=${KAFKA_DBDIR}|" ${WRKSRC}/config/server.properties
.for f in ${KAFKA_CONFIGS_KRAFT}
	@${REINPLACE_CMD} "/log.dirs/s|=.*|=${KAFKA_DBDIR_KRAFT}|" ${WRKSRC}/config/kraft/${f}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/kraft
	${MKDIR} ${STAGEDIR}${KAFKA_DBDIR}
	${MKDIR} ${STAGEDIR}${KAFKA_DBDIR_KRAFT}
	${MKDIR} ${STAGEDIR}${KAFKA_LOGDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
.for f in ${KAFKA_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${DATADIR}/bin/
.endfor
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} libs ${STAGEDIR}${DATADIR} "-not ( \
		-name kafka_*-javadoc\.jar -or -name kafka_*-scaladoc\.jar -or \
		-name kafka_*-sources\.jar -or -name kafka_*-test\.jar -or \
		-name *\.asc )" \
	)
.for f in ${KAFKA_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
.for f in ${KAFKA_CONFIGS_KRAFT}
	${INSTALL_DATA} ${WRKSRC}/config/kraft/${f} ${STAGEDIR}${ETCDIR}/kraft/${f}.sample
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${EXTRACT_CMD} -xf ${WRKSRC}/site-docs/${PORTNAME}_2.13-${PORTVERSION}-site-docs.tgz -C ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
