# New ports collection makefile for:	Cocoon
# Date created:		27 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cocoon
PORTVERSION=	2.1.7
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PDISTNAME}-src

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	XML Web Development Framework

USE_JAVA=		yes
JAVA_VERSION=		1.3+
USE_PYTHON=		1.6+
USE_REINPLACE=		YES
MAKE_ENV=		JAVA_HOME=${JAVA_HOME}
WRKSRC=			${WRKDIR}/${PDISTNAME}
APP_NAME?=		${PORTNAME}
APP_HOME?=		${PREFIX}/${APP_NAME}
LATEST_LINK=		${APP_NAME}
PLIST=			${WRKDIR}/pkg-plist
PKGMESSAGE=		${WRKDIR}/pkg-message
PDISTNAME=		${PORTNAME}-${PORTVERSION}
PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

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

SUBSTITUTIONS=	\
	-e "s|%%APP_HOME%%|${APP_HOME}|g" \
	-e "s|%%APP_NAME%%|${APP_NAME}|g" \
	-e "s|%%PREFIX%%|${PREFIX}|g" \
	-e "s|%%PORT%%|${PORT}|g" \
	-e "s|%%COCOON_LIB%%|${COCOON_LIB}|g" \
	-e "s|%%JAVA_HOME%%|${JAVA_HOME}|g" \
	-e "s|%%JAVA%%|${JAVA}|g" \
	-e "s|%%PID_FILE%%|${PID_FILE}|g" \
	-e "s|%%RUNASUSER%%|${RUNASUSER}|g" \
	-e "s|%%RUNASUID%%|${RUNASUID}|g" \
	-e "s|%%GROUP%%|${GROUP}|g" \
	-e "s|%%GID%%|${GID}|g" \
	-e "s|%%LOG_FILE%%|${LOG_FILE}|g" \
	-e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g"

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

	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/pkg-install > ${PKGINSTALL}
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/pkg-deinstall > ${PKGDEINSTALL}

do-install:
	@${ECHO_MSG} "===> Installing ${COPYDIRS}"
	@${MKDIR} ${APP_HOME}
	@cd ${WRKSRC} && ${FIND} -H ${COPYDIRS} | ${CPIO} -pdmuL -R ${LIBOWN}:${LIBGRP} ${APP_HOME}

	@${ECHO_MSG} "===> Installing into ${PREFIX}/sbin"
	@${SED} ${SUBSTITUTIONS} ${WRKSRC}/cocoon.sh > ${WRKDIR}/${APP_NAME}.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}.sh ${PREFIX}/sbin
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/${APP_NAME}ctl > ${WRKDIR}/${APP_NAME}ctl
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}ctl ${PREFIX}/sbin

	@${ECHO_MSG} "===> Installing ${PREFIX}/etc/rc.d/${APP_NAME}.sh"
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/${APP_NAME}.sh > ${WRKDIR}/${APP_NAME}.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/${APP_NAME}.sh ${PREFIX}/etc/rc.d

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} ${SUBSTITUTIONS} ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${ECHO_CMD}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE} | fmt -w 80
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
