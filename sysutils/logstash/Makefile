# Created by: Daniel Solsona <daniel@ish.com.au>, Guido Falsi <madpilot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstash
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	sysutils java
MASTER_SITES=	https://download.elasticsearch.org/logstash/logstash/:0 \
		https://github.com/emcrisostomo/jnr-ffi/releases/download/2.0.0/:1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:0 jnr-ffi-2.0.0.jar:1

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Tool for managing events and logs

LICENSE=	APACHE20

USE_JAVA=	yes
JAVA_VERSION=	1.7+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_BUILD=	yes

LOGSTASH_DIR=	${PREFIX}/${PORTNAME}

USE_RC_SUBR=	logstash

LOGSTASH_HOME?=	${PREFIX}/${PORTNAME}
LOGSTASH_RUN?=	/var/run/${PORTNAME}
LOGSTASH_DATA_DIR?=	/var/db/${PORTNAME}

SUB_LIST=	LOGSTASH_DATA_DIR=${LOGSTASH_DATA_DIR} JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME}

# Patch the logstash distribution using the patched jnr-ffi classes.
JRUBY_JAR=	jruby-complete-1.7.11.jar
post-patch:
	@-${RM} -r ${WRKSRC}/vendor/jar/temp
	@-${RM} ${WRKSRC}/vendor/jar/${JRUBY_JAR}.bak
	@(cd ${WRKSRC}/vendor/jar && \
	  ${MKDIR} temp && \
	  ${CP} ${JRUBY_JAR} temp && \
	  ${MV} ${JRUBY_JAR} ${JRUBY_JAR}.bak && \
	  cd temp && \
	  ${JAR} xf ${JRUBY_JAR} && \
	  ${RM} ${JRUBY_JAR} && \
	  ${RM} -r jnr/ffi)
	@(cd ${WRKDIR}/jnr && ${CP} -r ffi ${WRKSRC}/vendor/jar/temp/jnr)
	@(cd ${WRKSRC}/vendor/jar/temp && \
	  ${JAR} cfm ../${JRUBY_JAR} META-INF/MANIFEST.MF .)
	@(cd ${WRKSRC}/vendor/jar && ${RM} -r temp ${JRUBY_JAR}.bak)

LOGSTASH_BIN_FILES=	logstash logstash-web
do-install:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${LOGSTASH_RUN}
	${MKDIR} ${STAGEDIR}${LOGSTASH_DATA_DIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOGSTASH_DIR})
	${INSTALL_DATA} ${FILESDIR}/logstash.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/elasticsearch.yml.sample ${STAGEDIR}${ETCDIR}
.for x in ${LOGSTASH_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_DIR}/bin/${x}
.endfor

.include <bsd.port.mk>
