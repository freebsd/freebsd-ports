# New ports collection makefile for:	Cocoon
# Date created:		27 June 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cocoon
PORTVERSION=	2.1.5.1
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%,${PORTNAME},}
DISTNAME=	${PDISTNAME}-src

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	XML Web Development Framework

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_PYTHON=	1.6+
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}
WRKSRC=	${WRKDIR}/${PDISTNAME}
APP_VERSION=	${PORTVERSION:C/\..*$//}
APP_NAME?=	${PORTNAME}
APP_HOME?=	${PREFIX}/${APP_NAME}
LATEST_LINK=	${APP_NAME}
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message
PDISTNAME=	${PORTNAME}-${PORTVERSION}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

COCOON_LIB=	${JAVASHAREDIR}/${APP_NAME}
PLIST_SUB+=	"COCOON_LIB=${COCOON_LIB}"

COPYDIRS=	*.txt tools/jetty tools/loader legal

PORT?=		8888
PID_FILE?=	/var/run/${APP_NAME}.pid
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=		www
GID?=		80
LOGFILE?=	/var/log/${APP_NAME}.log

SUBSTITUTIONS=	\
	-e "s|%%APP_HOME%%|${APP_HOME}|g" \
	-e "s|%%APP_NAME%%|${APP_NAME}|g" \
	-e "s|%%PREFIX%%|${PREFIX}|g" \
	-e "s|%%PORT%%|${PORT}|g" \
	-e "s|%%COCOON_LIB%%|${COCOON_LIB}|g" \
	-e "s|%%JAVA_HOME%%|${JAVA_HOME}|g" \
	-e "s|%%PID_FILE%%|${PID_FILE}|g" \
	-e "s|%%RUNASUSER%%|${RUNASUSER}|g" \
	-e "s|%%RUNASUID%%|${RUNASUID}|g" \
	-e "s|%%GROUP%%|${GROUP}|g" \
	-e "s|%%GID%%|${GID}|g" \
	-e "s|%%LOGFILE%%|${LOGFILE}|g" \
	-e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g"

# Load options (before including bsd.port.pre.mk)
.include "${.CURDIR}/Makefile.options"

.include <bsd.port.pre.mk>

# Test for options
.include "${MASTERDIR}/Makefile.test-options"

.for BLOCK in ${BLOCKS}
BLOCKSEXP+=	-e 's/^include.block.${BLOCK}=.*$$/include.block.${BLOCK}=true/'
.endfor

post-patch:
	@${ECHO_MSG} "===> Configuring blocks: ${BLOCKS}"
	${SED} -e 's/.*include.block\(.*\)=.*$$/include.block\1=false/' < ${WRKSRC}/blocks.properties | \
	${SED} ${BLOCKSEXP} > ${WRKSRC}/local.blocks.properties
.if (! defined(WITH_DOCS))
	${SED} -e 's/^#exclude/exclude/' < ${WRKSRC}/build.properties \
	> ${WRKSRC}/local.build.properties
.endif

pre-build:
	${CHMOD} a+rx ${WRKSRC}/build.sh

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build.sh

post-build:
	@${ECHO_MSG} "===> Building packing list"
	@> ${PLIST}

	@cd ${WRKSRC}/build && ${FIND} webapp -type f \
	| ${SED} -e "s|^|${APP_NAME}/|" >> ${PLIST}

	@cd ${WRKSRC}/build && ${FIND} -d webapp -type d \
	| ${SED} -e "s|^|@dirrm ${APP_NAME}/|" >> ${PLIST}

	@${CAT} ${MASTERDIR}/pkg-plist >> ${PLIST}

	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/pkg-install > ${PKGINSTALL}
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/pkg-deinstall > ${PKGDEINSTALL}

do-install:
	@${ECHO_MSG} "===> Installing ${COPYDIRS}"
	@${MKDIR} ${APP_HOME}
	@cd ${WRKSRC} && ${FIND} ${COPYDIRS} \
	| ${XARGS} ${TAR} -C ${WRKSRC} -cf- | ${TAR} -C ${APP_HOME} -xpf-

	@${ECHO_MSG} "===> Installing webapp"
	@cd ${WRKSRC}/build && ${FIND} webapp \
	| ${XARGS} ${TAR} -C ${WRKSRC}/build -cf- | ${TAR} -C ${APP_HOME} -xpf-

	@${ECHO_MSG} "===> Installing into ${PREFIX}/sbin"
	@${SED} ${SUBSTITUTIONS} ${WRKSRC}/cocoon.sh > ${WRKDIR}/${APP_NAME}.sh
	@${INSTALL} ${WRKDIR}/${APP_NAME}.sh ${PREFIX}/sbin
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/${APP_NAME}ctl > ${WRKDIR}/${APP_NAME}ctl
	@${INSTALL} ${WRKDIR}/${APP_NAME}ctl ${PREFIX}/sbin

	@${ECHO_MSG} "===> Installing ${PREFIX}/etc/rc.d/${APP_NAME}.sh"
	@${SED} ${SUBSTITUTIONS} ${FILESDIR}/${APP_NAME}.sh > ${WRKDIR}/${APP_NAME}.sh
	@${INSTALL} ${WRKDIR}/${APP_NAME}.sh ${PREFIX}/etc/rc.d

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${SED} ${SUBSTITUTIONS} ${MASTERDIR}/pkg-message > ${PKGMESSAGE}
	@${ECHO_CMD}
	@${ECHO_CMD} "********************************************************************************"
	@${CAT} ${PKGMESSAGE} | fmt -w 80
	@${ECHO_CMD} "********************************************************************************"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
