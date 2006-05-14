# New ports collection makefile for:	Cocoon
# Date created:		27 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cocoon
PORTVERSION=	2.1.9
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PDISTNAME}-src

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	XML Web Development Framework

USE_RC_SUBR=		${PORTNAME}.sh
USE_JAVA=		yes
JAVA_VERSION=		1.3+
USE_PYTHON=		1.6+
MAKE_ENV=		JAVA_HOME=${JAVA_HOME}
WRKSRC=			${WRKDIR}/${PDISTNAME}
APP_NAME?=		${PORTNAME}
APP_HOME?=		${PREFIX}/${APP_NAME}
LATEST_LINK=		${APP_NAME}
PLIST=			${WRKDIR}/pkg-plist
PDISTNAME=		${PORTNAME}-${PORTVERSION}

COCOON_LIB=	${JAVASHAREDIR}/${APP_NAME}
PLIST_SUB+=	"COCOON_LIB=${COCOON_LIB}"

COPYDIRS=	*.txt tools/jetty tools/loader legal webapp

PORT?=		8888
PID_FILE?=	${APP_HOME}/${APP_NAME}.pid
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=		www
GID?=		80
LOG_FILE?=	${APP_HOME}/${APP_NAME}.log

SUB_LIST=	\
		APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		RC_SUBR=${RC_SUBR} \
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

SUB_FILES=	\
		pkg-install \
		pkg-deinstall \
		${APP_NAME}ctl \
		${APP_NAME}.sh \
		upstreams-cocoon.sh \
		pkg-message

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
.if (! defined(WITH_DOCS))
	${REINPLACE_CMD} \
       	-e 's/^#\(exclude.webapp.documentation=\)/\1/' \
       	-e 's/^#\(exclude.webapp.javadocs=\)/\1/' \
       	-e 's/^#\(exclude.documentation=\)/\1/' \
       	-e 's/^#\(exclude.javadocs=\)/\1/' \
       	${WRKSRC}/local.build.properties
.endif
.if (! defined(WITH_SAMPLES))
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

	@cd ${WRKSRC} && ${FIND} -H ${COPYDIRS} -type f \
	| ${SED} -e "s|^|${APP_NAME}/|" >> ${PLIST}

	@cd ${WRKSRC} && ${FIND} -H -d ${COPYDIRS} -type d \
	| ${SED} -e "s|^|@dirrm ${APP_NAME}/|" >> ${PLIST}

	@${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

do-install:
	@${ECHO_MSG} "===> Installing ${COPYDIRS}"
	@${MKDIR} ${APP_HOME}
	@cd ${WRKSRC} && ${FIND} -H ${COPYDIRS} | ${CPIO} -pdmuL -R ${LIBOWN}:${LIBGRP} ${APP_HOME}
	@${INSTALL} ${WRKDIR}/upstreams-cocoon.sh ${APP_HOME}/cocoon.sh

	@${ECHO_MSG} "===> Installing into ${PREFIX}/sbin"
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}ctl ${PREFIX}/sbin

	@${ECHO_MSG} "===> Installing ${PREFIX}/etc/rc.d/${APP_NAME}.sh"
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}.sh ${PREFIX}/etc/rc.d

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_CMD}
	@${ECHO_CMD} "********************************************************************************"
	@${FMT} -w80 ${PKGMESSAGE}
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
