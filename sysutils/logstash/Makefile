# Created by: Daniel Solsona <daniel@ish.com.au>, Guido Falsi <madpilot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstash
PORTVERSION=	1.1.13
CATEGORIES=	sysutils java
MASTER_SITES=	https://logstash.objects.dreamhost.com/release/ \
		http://semicomplete.com/files/logstash/
DISTNAME=	${PORTNAME}-${PORTVERSION}-flatjar
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	regis.despres@gmail.com
COMMENT=	Tool for managing events and logs

USE_JAVA=	yes
JAVA_VERSION=	1.5+

NO_BUILD=	yes

USE_RC_SUBR=	logstash

LOGSTASH_HOME?=	${PREFIX}/${PORTNAME}
LOGSTASH_HOME_REL?=	${LOGSTASH_HOME:S,^${PREFIX}/,,}
LOGSTASH_JAR?=	${DISTNAME}${EXTRACT_SUFX}
LOGSTASH_RUN?=	/var/run/${PORTNAME}
LOGSTASH_DATA_DIR?=	/var/db/${PORTNAME}

SUB_LIST=	LOGSTASH_DATA_DIR=${LOGSTASH_DATA_DIR} JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME} LOGSTASH_JAR=${LOGSTASH_JAR}
PLIST_SUB+=	LOGSTASH_HOME=${LOGSTASH_HOME_REL} LOGSTASH_JAR=${LOGSTASH_JAR} \
		LOGSTASH_RUN=${LOGSTASH_RUN} \
		LOGSTASH_DATA_DIR=${LOGSTASH_DATA_DIR}

do-install:
	${MKDIR} ${LOGSTASH_RUN}
	${MKDIR} ${ETCDIR}
	${MKDIR} ${LOGSTASH_HOME}
	${MKDIR} ${LOGSTASH_DATA_DIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${LOGSTASH_JAR} ${LOGSTASH_HOME}
	${INSTALL_DATA} ${FILESDIR}/logstash.conf.sample ${ETCDIR}
	@if [ ! -f ${ETCDIR}/logstash.conf ]; then \
		${CP} -p ${ETCDIR}/logstash.conf.sample ${ETCDIR}/logstash.conf ; \
	fi
	${INSTALL_DATA} ${FILESDIR}/elasticsearch.yml.sample ${ETCDIR}
	@if [ ! -f ${ETCDIR}/elasticsearch.yml ]; then \
		${CP} -p ${ETCDIR}/elasticsearch.yml.sample ${ETCDIR}/elasticsearch.yml ; \
	fi

.include <bsd.port.mk>
