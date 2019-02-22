# $FreeBSD$

PORTNAME=	kafka
PORTVERSION=	2.1.1
CATEGORIES=	net java
MASTER_SITES=	APACHE/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}_2.12-${PORTVERSION}

MAINTAINER=	timp87@gmail.com
COMMENT=	Distributed streaming platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		tar:tgz shebangfix

SHEBANG_FILES=	bin/*.sh

OPTIONS_DEFINE=	DOCS

USERS=		kafka
GROUPS=		kafka

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
KAFKA_DATADIR=	/var/db/${PORTNAME}
KAFKA_LOGDIR=	/var/log/${PORTNAME}
KAFKA_RUNDIR=	/var/run/${PORTNAME}
KAFKA_BINS=	connect-distributed.sh connect-standalone.sh kafka-acls.sh \
		kafka-broker-api-versions.sh kafka-configs.sh \
		kafka-console-consumer.sh kafka-console-producer.sh \
		kafka-consumer-groups.sh kafka-consumer-perf-test.sh \
		kafka-delegation-tokens.sh \
		kafka-delete-records.sh kafka-dump-log.sh kafka-log-dirs.sh \
		kafka-mirror-maker.sh kafka-preferred-replica-election.sh \
		kafka-producer-perf-test.sh kafka-reassign-partitions.sh \
		kafka-replica-verification.sh \
		kafka-run-class.sh kafka-server-start.sh kafka-server-stop.sh \
		kafka-streams-application-reset.sh kafka-topics.sh \
		kafka-verifiable-consumer.sh kafka-verifiable-producer.sh \
		trogdor.sh zookeeper-security-migration.sh
KAFKA_CONFIGS=	connect-console-sink.properties \
		connect-console-source.properties \
		connect-distributed.properties connect-file-sink.properties \
		connect-file-source.properties connect-log4j.properties \
		connect-standalone.properties consumer.properties \
		log4j.properties producer.properties server.properties \
		tools-log4j.properties trogdor.conf

SUB_FILES=	kafka
SUB_LIST=	JAVA=${JAVA} \
		ETCDIR=${ETCDIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		KAFKA_RUNDIR=${KAFKA_RUNDIR} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR}

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		USERS=${USERS} \
		GROUPS=${GROUPS} \
		KAFKA_DATADIR=${KAFKA_DATADIR} \
		KAFKA_RUNDIR=${KAFKA_RUNDIR} \
		KAFKA_LOGDIR=${KAFKA_LOGDIR} \
		ETCDIR=${ETCDIR}

NO_BUILD=	yes
NO_ARCH=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8+
USE_RC_SUBR=	kafka

post-patch:
	@${REINPLACE_CMD} "s|JAVA=\"java\"|JAVA=\"${JAVA}\"|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "/LOG_DIR=/s|\$$base_dir/logs|${KAFKA_LOGDIR}|" ${WRKSRC}/bin/kafka-run-class.sh
	@${REINPLACE_CMD} "s|\$$base_dir.*/config|${ETCDIR}|" ${WRKSRC}/bin/*.sh
	@${REINPLACE_CMD} "s|ps ax|ps axww|" ${WRKSRC}/bin/kafka-server-stop.sh
	@${REINPLACE_CMD} "/log.dirs/s|=.*|=${KAFKA_DATADIR}|" ${WRKSRC}/config/server.properties

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${KAFKA_DATADIR}
	${MKDIR} ${STAGEDIR}${KAFKA_LOGDIR}
	${MKDIR} ${STAGEDIR}${KAFKA_RUNDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
.for f in ${KAFKA_BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${DATADIR}/bin/
.endfor
	(cd ${WRKSRC} && ${COPYTREE_SHARE} libs ${STAGEDIR}${DATADIR} "-not ( \
		-name kafka_*-javadoc\.jar -or -name kafka_*-scaladoc\.jar -or \
		-name kafka_*-sources\.jar -or -name kafka_*-test\.jar -or \
		-name *\.asc \
		)" \
	)
.for f in ${KAFKA_CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${EXTRACT_CMD} -xf ${WRKSRC}/site-docs/${PORTNAME}_2.12-${PORTVERSION}-site-docs.tgz -C ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
