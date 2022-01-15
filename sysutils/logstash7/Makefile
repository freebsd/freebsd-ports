# Created by: Daniel Solsona <daniel@ish.com.au>, Guido Falsi <madpilot@FreeBSD.org>

PORTNAME=	logstash
PORTVERSION=	7.16.3
DISTVERSIONSUFFIX=	-darwin-x86_64
CATEGORIES=	sysutils java
MASTER_SITES=	https://artifacts.elastic.co/downloads/logstash/
PKGNAMESUFFIX=	7

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Server-side data ingestion and transformation tool

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		cpe shebangfix

CPE_VENDOR=	elastic
USE_JAVA=	yes
JAVA_VERSION=	11+
JAVA_RUN=	yes
USE_RC_SUBR=	logstash

SHEBANG_FILES=	bin/*

CONFLICTS=	logstash5 logstash6

NO_BUILD=	yes
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USERS=		logstash
GROUPS=		logstash

LOGSTASH_CONF_FILES=		jvm.options log4j2.properties logstash.yml \
				pipelines.yml startup.options
LOGSTASH_HOME?=			${PREFIX}/${PORTNAME}
LOGSTASH_JRUBY_BIN_FILES=	ast gem irb jgem jirb jirb_swing jruby \
				jruby.bash jruby.sh jrubyc rake rdoc ri testrb
LOGSTASH_JRUBY_SUBDIR=		vendor/jruby/bin

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
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOGSTASH_HOME})
	${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_HOME}/bin/*
.for x in ${LOGSTASH_JRUBY_BIN_FILES}
	${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_HOME}/${LOGSTASH_JRUBY_SUBDIR}/${x}
.endfor
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${LOGSTASH_HOME}/config
	${RM} -rf ${STAGEDIR}${LOGSTASH_HOME}/vendor/jruby/lib/jni
	${MKDIR} ${STAGEDIR}${LOGSTASH_HOME}/vendor/jruby/lib/jni
	(cd ${WRKSRC}/vendor/jruby/lib/jni && \
	 ${COPYTREE_SHARE} ${ARCH:S/amd64/x86_64/}-FreeBSD \
	 ${STAGEDIR}${LOGSTASH_HOME}/vendor/jruby/lib/jni)


post-install:
	${ECHO} "@sample ${ETCDIR}/logstash.conf.sample" >> ${TMPPLIST}
.for x in ${LOGSTASH_CONF_FILES}
	${ECHO} "@sample ${ETCDIR}/${x}.sample" >> ${TMPPLIST}
.endfor
	${ECHO} "@dir logstash/vendor/bundle/jruby/2.5.0/build_info" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/2.5.0/cache" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/2.5.0/doc" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/2.5.0/extensions" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/2.5.0/gems/manticore-0.7.1-java/spec/ssl" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/jruby/lib/ruby/gems/shared/cache" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/logstash -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(logstash,logstash,) logstash/data" >> ${TMPPLIST}

.include <bsd.port.mk>
