# Created by: Daniel Solsona <daniel@ish.com.au>, Guido Falsi <madpilot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	logstash
PORTVERSION=	5.1.1
CATEGORIES=	sysutils java
MASTER_SITES=	http://artifacts.elastic.co/downloads/logstash/
PKGNAMESUFFIX=	5

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Server-side data ingest and transfomation tool

LICENSE=	APACHE20

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

CONFLICTS=	logstash-[0-9]

USES=		cpe
CPE_VENDOR=	elasticsearch
USE_JAVA=	yes
JAVA_VERSION=	1.8+
JAVA_EXTRACT=	yes
JAVA_RUN=	yes
NO_BUILD=	yes

USERS=	logstash
GROUPS=	logstash
PLIST_SUB=	FIND=${FIND} \
			XARGS=${XARGS} \
			CHMOD=${CHMOD} \
			CHOWN=${CHOWN} \
			USERS=${USERS} \
			GROUPS=${GROUPS}

LOGSTASH_DIR=	${PREFIX}/${PORTNAME}

USE_RC_SUBR=	logstash

LOGSTASH_HOME?=	${PREFIX}/${PORTNAME}
LOGSTASH_RUN?=	/var/run/${PORTNAME}
LOGSTASH_DATA_DIR?=	/var/db/${PORTNAME}

SUB_LIST=	LOGSTASH_DATA_DIR=${LOGSTASH_DATA_DIR} JAVA_HOME=${JAVA_HOME} \
		LOGSTASH_HOME=${LOGSTASH_HOME}

LOGSTASH_BIN_FILES=	  cpdump \
					  logstash \
					  logstash-plugin \
					  system-install
LOGSTASH_JRUBY_SUBDIR=	  vendor/jruby/bin
LOGSTASH_JRUBY_BIN_FILES=	ast irb jirb jruby jruby.sh rdoc testrb gem \
				jgem jirb_swing jruby.bash jrubyc rake ri
LOGSTASH_VENDOR_SUBDIR=	vendor

do-install:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${LOGSTASH_RUN}
	${MKDIR} ${STAGEDIR}${LOGSTASH_DATA_DIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${LOGSTASH_DIR})
	${INSTALL_DATA} ${FILESDIR}/logstash.conf.sample ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config/log4j2.properties ${STAGEDIR}${ETCDIR}/log4j2.properties.sample
	${INSTALL_DATA} ${WRKSRC}/config/jvm.options ${STAGEDIR}${ETCDIR}/jvm.options.sample
.for x in ${LOGSTASH_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_DIR}/bin/${x}
.endfor
.for x in ${LOGSTASH_JRUBY_BIN_FILES}
	@${CHMOD} ${BINMODE} ${STAGEDIR}${LOGSTASH_DIR}/${LOGSTASH_JRUBY_SUBDIR}/${x}
.endfor
	${FIND} ${STAGEDIR}${LOGSTASH_DIR}/${LOGSTASH_VENDOR_SUBDIR} -type d -name bin | ${XARGS} ${FIND} | ${XARGS} ${CHMOD} ${BINMODE}

.include <bsd.port.mk>
