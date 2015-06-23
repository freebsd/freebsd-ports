# $FreeBSD$

PORTNAME=	cocoon
PORTVERSION=	2.1.11
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	APACHE/${PORTNAME}
DISTNAME=	${PDISTNAME}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Web Development Framework

USE_RC_SUBR=	${PORTNAME}
USE_JAVA=	yes
JAVA_VERSION=	1.6
USES=		cpe python
CPE_VENDOR=	apache
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}
WRKSRC=		${WRKDIR}/${PDISTNAME}
APP_NAME?=	${PORTNAME}
APP_HOME?=	${PREFIX}/${APP_NAME}
LATEST_LINK=	${APP_NAME}
PLIST=		${WRKDIR}/pkg-plist
PDISTNAME=	${PORTNAME}-${PORTVERSION}
PKGMESSAGE=	${WRKDIR}/pkg-message
NO_ARCH=	yes

COCOON_LIB=	${JAVASHAREDIR}/${APP_NAME}
PLIST_SUB+=	COCOON_LIB="${COCOON_LIB}"

COPYDIRS=	*.txt tools/jetty tools/loader legal webapp

PORT?=		8888
PID_FILE?=	${APP_HOME}/${APP_NAME}.pid
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=		www
GID?=		80
LOG_FILE?=	${APP_HOME}/${APP_NAME}.log

SUB_LIST=	APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		PORT=${PORT} \
		COCOON_LIB=${COCOON_LIB} \
		JAVA_HOME=${JAVA_HOME} \
		JAVA=${JAVA} \
		PID_FILE=${PID_FILE} \
		RUNASUSER=${RUNASUSER} \
		RUNASUID=${RUNASUID} \
		GROUP=${GROUP} \
		GID=${GID} \
		LOG_FILE=${LOG_FILE} \
		PYTHON_CMD=${PYTHON_CMD}

SUB_FILES=	pkg-install \
		pkg-deinstall \
		${APP_NAME}ctl \
		upstreams-cocoon.sh \
		message \
		message-advanced

# Load options (before including bsd.port.pre.mk)
.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

# Test for options
.include "${MASTERDIR}/Makefile.test-options"

.for BLOCK in ${BLOCKS}
BLOCKSEXP+=	-e 's/^include.block.${BLOCK}=.*$$/include.block.${BLOCK}=true/'
.endfor

post-configure:
	@${ECHO_MSG} "===> Configuring blocks: ${BLOCKS}"
	${SED} -e 's/.*include.block\(.*\)=.*$$/include.block\1=false/' < ${WRKSRC}/blocks.properties | \
	${SED} ${BLOCKSEXP} > ${WRKSRC}/local.blocks.properties
	${CP} ${WRKSRC}/build.properties ${WRKSRC}/local.build.properties
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} \
		-e 's/^#\(exclude.webapp.documentation=\)/\1/' \
		-e 's/^#\(exclude.webapp.javadocs=\)/\1/' \
		-e 's/^#\(exclude.documentation=\)/\1/' \
		-e 's/^#\(exclude.javadocs=\)/\1/' \
		${WRKSRC}/local.build.properties
.endif
.if ! ${PORT_OPTIONS:MSAMPLES}
	${REINPLACE_CMD} \
		-e 's/^#\(exclude.webapp.samples=\)/\1/' \
		-e 's/^#\(exclude.webapp.test-suite=\)/\1/' \
		${WRKSRC}/local.build.properties
.endif
# Include Java source code into the binary jar files
.if (defined(WITH_SOURCES))
	${REINPLACE_CMD} \
		-e 's/^#\(include.sources-in-jars=\)/\1/' \
		${WRKSRC}/local.build.properties
.endif

pre-build:
	${CHMOD} a+rx ${WRKSRC}/build.sh

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

post-build:
	${TEST} -h ${WRKSRC}/webapp || ${LN} -s ${WRKSRC}/build/webapp ${WRKSRC}/webapp

	@${ECHO_MSG} "===> Building packing list"
	@> ${PLIST}

	@cd ${WRKSRC} && ${FIND} -H ${COPYDIRS} -not -type d \
	| ${SED} -e "s|^|${APP_NAME}/|" >> ${PLIST}

	@cd ${WRKSRC} && ${FIND} -H -d ${COPYDIRS} -type d -empty \
	| ${SED} -e "s|^|@dir ${APP_NAME}/|" >> ${PLIST}

	@${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

pre-install:
	@${FMT} -w80 ${WRKDIR}/message > ${PKGMESSAGE}
	@${CAT} ${WRKDIR}/message-advanced >> ${PKGMESSAGE}

do-install:
	@${ECHO_MSG} "===> Installing ${COPYDIRS}"
	@${MKDIR} ${STAGEDIR}${APP_HOME}
	@cd ${WRKSRC} && ${FIND} -H ${COPYDIRS} | ${CPIO} -pdmuL -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${APP_HOME}
	@${INSTALL} ${WRKDIR}/upstreams-cocoon.sh ${STAGEDIR}${APP_HOME}/cocoon.sh

	@${ECHO_MSG} "===> Installing into ${PREFIX}/sbin"
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}ctl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.post.mk>
