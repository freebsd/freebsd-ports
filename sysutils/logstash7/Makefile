# Created by: Daniel Solsona <daniel@ish.com.au>, Guido Falsi <madpilot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstash
PORTVERSION=	7.6.1
CATEGORIES=	sysutils java
MASTER_SITES=	http://artifacts.elastic.co/downloads/logstash/
PKGNAMESUFFIX=	7

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Server-side data ingest and transfomation tool

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		cpe shebangfix

CONFLICTS=	logstash5-[0-9]* logstash6-[0-9]*

SHEBANG_FILES=	bin/*
CPE_VENDOR=	elasticsearch
USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_RUN=	yes
NO_BUILD=	yes

USERS=	logstash
GROUPS=	logstash

LOGSTASH_DIR=	${PREFIX}/${PORTNAME}

USE_RC_SUBR=	logstash

LOGSTASH_HOME?=	${PREFIX}/${PORTNAME}

SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME}

LOGSTASH_CONF_FILES=	jvm.options log4j2.properties logstash.yml \
			pipelines.yml startup.options
LOGSTASH_JRUBY_SUBDIR=	vendor/jruby/bin
LOGSTASH_JRUBY_BIN_FILES=	ast gem irb jgem jirb jirb_swing jruby \
				jruby.bash jruby.sh jrubyc rake rdoc ri testrb

post-patch:
	${REINPLACE_CMD} 's|%%ETCDIR%%|${ETCDIR}|g' ${WRKSRC}/config/logstash.yml
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${FIND} ${WRKSRC} -name '*.bat' -delete
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/logstash.conf.sample ${STAGEDIR}${ETCDIR}
.for x in ${LOGSTASH_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${x} ${STAGEDIR}${ETCDIR}/${x}.sample
.endfor
	${RM} -rf ${WRKSRC}/config
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOGSTASH_DIR})
	${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_DIR}/bin/*
.for x in ${LOGSTASH_JRUBY_BIN_FILES}
	${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_DIR}/${LOGSTASH_JRUBY_SUBDIR}/${x}
.endfor
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${LOGSTASH_DIR}/config

post-install:
	${ECHO} "@sample ${ETCDIR}/logstash.conf.sample" >> ${TMPPLIST}
.for x in ${LOGSTASH_CONF_FILES}
	${ECHO} "@sample ${ETCDIR}/${x}.sample" >> ${TMPPLIST}
.endfor
	${FIND} -s ${STAGEDIR}${PREFIX}/logstash -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(logstash,logstash,) logstash/data" >> ${TMPPLIST}

.include <bsd.port.mk>
