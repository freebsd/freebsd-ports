PORTNAME=	logstash
DISTVERSION=	9.3.1
DISTVERSIONSUFFIX=	-darwin-x86_64
CATEGORIES=	sysutils java
MASTER_SITES=	https://artifacts.elastic.co/downloads/logstash/ \
		LOCAL/vvd/elastic
PKGNAMESUFFIX=	93

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Server-side data ingestion and transformation tool (9.3.x version)
WWW=		https://www.elastic.co/products/logstash

LICENSE=	APACHE20

ONLY_FOR_ARCHS=	aarch64 amd64

RUN_DEPENDS=	bash:shells/bash

USES=		cpe java:run shebangfix
CPE_VENDOR=	elastic
JAVA_VERSION=	25 21 17
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/*

CONFLICTS=	${PORTNAME}7 ${PORTNAME}8 ${PORTNAME}91 ${PORTNAME}92

EXTRACT_AFTER_ARGS=	--exclude jdk.app \
			--exclude *.bat \
			--no-same-owner --no-same-permissions

NO_BUILD=	yes
PORTSCOUT=	limit:^9\.3\.
SUB_FILES=	pkg-message
SUB_LIST=	JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME} \
		LOGUSER=${LOGUSER} \
		LOGGROUP=${LOGGROUP}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

LOGUSER?=	${PORTNAME}
LOGGROUP?=	${LOGUSER}
.if ${LOGUSER} == ${PORTNAME}
USERS=		${LOGUSER}
.endif
.if ${LOGGROUP} == ${PORTNAME}
GROUPS=		${LOGGROUP}
.endif

LOGSTASH_CONF_FILES=		jvm.options log4j2.properties logstash.yml \
				pipelines.yml startup.options
LOGSTASH_HOME?=			${PREFIX}/${PORTNAME}
LOGSTASH_JRUBY_BIN_FILES=	ast gem irb jgem jirb jirb_swing jruby \
				jruby.sh jrubyc rake rdoc ri
LOGSTASH_JRUBY_SUBDIR=		vendor/jruby/bin

post-patch:
	${REINPLACE_CMD} 's|%%ETCDIR%%|${ETCDIR}|g' ${WRKSRC}/config/logstash.yml
	${FIND} ${WRKSRC} -name '*.orig' -delete

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/logstash.conf.sample ${STAGEDIR}${ETCDIR}
.for x in ${LOGSTASH_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/config/${x} ${STAGEDIR}${ETCDIR}/${x}.sample
.endfor
	${RM} -rf ${WRKSRC}/config
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOGSTASH_HOME})
	${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_HOME}/bin/* \
		${LOGSTASH_JRUBY_BIN_FILES:S|^|${STAGEDIR}${LOGSTASH_HOME}/${LOGSTASH_JRUBY_SUBDIR}/|}
	${FIND} ${STAGEDIR}${LOGSTASH_HOME}/vendor/bundle/jruby/3.1.0/gems \
	        ${STAGEDIR}${LOGSTASH_HOME}/vendor/bundle/jruby/3.1.0/plugins \
		${STAGEDIR}${LOGSTASH_HOME}/vendor/jruby/lib/ruby/gems/shared/gems \
		-type d -empty -delete
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${LOGSTASH_HOME}/config

post-install:
	${ECHO} "@sample ${ETCDIR}/logstash.conf.sample" >> ${TMPPLIST}
.for x in ${LOGSTASH_CONF_FILES}
	${ECHO} "@sample ${ETCDIR}/${x}.sample" >> ${TMPPLIST}
.endfor
	${ECHO} "@dir logstash/vendor/bundle/jruby/3.1.0/build_info" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/3.1.0/cache" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/3.1.0/doc" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/bundle/jruby/3.1.0/extensions" >> ${TMPPLIST}
	${ECHO} "@dir logstash/vendor/jruby/lib/ruby/gems/shared/cache" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${LOGSTASH_HOME} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir(${LOGUSER},${LOGGROUP},) logstash/data" >> ${TMPPLIST}

.include <bsd.port.mk>
