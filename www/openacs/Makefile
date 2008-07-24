# New ports collection makefile for:    openACS
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <aldert@nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME?=	openacs
DISTVERSION?=	5.4.2
CATEGORIES=	www
MASTER_SITES?=	http://openacs.org/projects/openacs/download/download/
EXTRACT_SUFX=	.tgz?revision_id=${DIST_REV_ID}

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	A modular web application platform for communities

DIST_REV_ID?=	1570341

AOLSERVERBASE?=	${LOCALBASE}/aolserver
RUN_DEPENDS+=	${AOLSERVERBASE}/bin/nscache.so:${PORTSDIR}/www/aolserver-nscache \
		${AOLSERVERBASE}/bin/nsopenssl.so:${PORTSDIR}/security/aolserver-nsopenssl \
		${AOLSERVERBASE}/bin/nssha1.so:${PORTSDIR}/security/aolserver-nssha1 \
		${AOLSERVERBASE}/bin/nspostgres.so:${PORTSDIR}/databases/aolserver-nspostgres \
		${AOLSERVERBASE}/modules/tcl/xotcl.tcl:${PORTSDIR}/www/aolserver-xotcl \
		dtplite:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tdomConfig.sh:${PORTSDIR}/www/tdom

USE_RC_SUBR?=	${PORTNAME}
NO_BUILD=	yes

OPENACS_USER?=	${PORTNAME}
OPENACS_GROUP?=	${PORTNAME}
PGUSER?=	pgsql
OPENACS_DB?=	${PORTNAME}
OPENACSBASE?=	${PREFIX}/openacs
OPENACSNAME?=	OpenACS
SU?=		/usr/bin/su
PGREP?=		/usr/bin/pgrep
PW?=		/usr/sbin/pw

BASE_INSTALL?=	bin content-repository-content-files log packages tcl www
PLIST=		${WRKDIR}/plist.tmp

SUB_FILES+=	pkg-install pkg-deinstall pkg-message ${PORTNAME} \
		create_sampledb.sh adjust_pgsql_conf.sh
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

PORTDOCS=	*

OPTIONS=	TCLTHREAD "Depend on tclthread" on \
		TCLWEBTEST "Depend on tclwebteset" on

.include <bsd.port.pre.mk>

# Parse ${PORTSDIR}/UIDs and GIDs for the defaults
USER!=	${GREP} -E '^${OPENACS_USER}:' ${PORTSDIR}/UIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):([^:]*)::0:0:([^:]*):([^:]*):([^:]*)$$/USER="\1" UID="\3" GECOS="\5" HOME="\6" SHELL="\7"/'
GROUP!=	${GREP} -E '^${OPENACS_GROUP}:' ${PORTSDIR}/GIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):$$/GROUP="\1" GID="\3"/'

# Apply the defaults where necessary
OPENACS_USER?=	${USER:MUSER*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_UID?=	${USER:MUID*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_GECOS?=	${USER:MGECOS*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_HOME?=	${USER:MHOME*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_SHELL?=	${USER:MSHELL*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_GROUP?=	${GROUP:MGROUP*:C/^[^=]*=\"([^\"]*)\"$/\1/}
OPENACS_GID?=	${GROUP:MGID*:C/^[^=]*=\"([^\"]*)\"$/\1/}

SUB_LIST+=	OPENACS_USER=${OPENACS_USER} OPENACS_UID=${OPENACS_UID} \
		OPENACS_GECOS="${OPENACS_GECOS}" \
		OPENACS_HOME="${OPENACS_HOME}" \
		OPENACS_SHELL="${OPENACS_SHELL}" \
		OPENACS_GROUP=${OPENACS_GROUP} \
		OPENACS_GID=${OPENACS_GID} \
		OPENACSBASE=${OPENACSBASE} OPENACS_DB=${OPENACS_DB} \
		PGUSER=${PGUSER} AOLSERVERBASE=${AOLSERVERBASE} \
		PORTNAME=${PORTNAME} OPENACSNAME=${OPENACSNAME} \
		SU=${SU} PGREP=${PGREP} AWK=${AWK} CP=${CP} GREP=${GREP} \
		PW=${PW} CHOWN=${CHOWN} CHMOD=${CHMOD}

.if !defined(WITHOUT_TCLTHREAD)
TCLTHREAD_VER?=	2.6.5
RUN_DEPENDS+=	${LOCALBASE}/lib/thread${TCLTHREAD_VER}/libthread${TCLTHREAD_VER}.so:${PORTSDIR}/devel/tclthread
.endif

.if !defined(WITHOUT_TCLWEBTEST)
RUN_DEPENDS+=	${LOCALBASE}/bin/tclwebtest:${PORTSDIR}/www/tclwebtest
.endif

post-patch:
	@${SED} -e 's|service0|${OPENACS_USER}|' \
		-e 's|/var/www/$${server}|${OPENACSBASE}|' \
		-e 's|/usr/lib/aolserver4|${AOLSERVERBASE}|' \
		-e 's|127.0.0.1|0.0.0.0|' \
		${WRKSRC}/etc/config.tcl > ${WRKDIR}/${PORTNAME}-config.tcl
pre-install:
	@ ${ECHO} "Generating plist"
	@ ${FIND} ${WRKSRC} ! -type d ! -path '${WRKSRC}/etc*' \
		! -path '${WRKSRC}/readme.txt' ! -path '${WRKSRC}/license.txt' \
		! -path '${WRKSRC}/ChangeLog' | \
		${SED} 's|${WRKSRC}|${OPENACSBASE:S/${PREFIX}\///}|' > ${PLIST}
	@ ${ECHO} @unexec if cmp -hsz %D/%%EXAMPLESDIR%%/config.tcl %D/${OPENACSBASE:S/${PREFIX}\///}/etc/${PORTNAME}-config.tcl \; then ${RM} %D/${OPENACSBASE:S/${PREFIX}\///}/etc/${PORTNAME}-config.tcl \; fi >> ${PLIST}
	@ ${FIND} ${WRKSRC}/etc ! -type d | \
		${SED} 's|${WRKSRC}/etc|%%EXAMPLESDIR%%|' >> ${PLIST}
	@ ${ECHO} @exec if ! [ -f ${OPENACSBASE:S/%D\///}/etc/${PORTNAME}-config.tcl ] \; then ${MKDIR} %D/${OPENACSBASE:S/${PREFIX}\///}/etc \; ${CP} %D/%%EXAMPLESDIR%%/config.tcl %D/${OPENACSBASE:S/${PREFIX}\///}/etc/${PORTNAME}-config.tcl \; fi >> ${PLIST}
	@ ${ECHO} @dirrmtry ${OPENACSBASE:S/${PREFIX}\///}/etc >> ${PLIST}
	@ ${FIND} ${WRKSRC} -type d ! -path '${WRKSRC}/etc*' | \
		${SORT} -r | \
		${SED} 's|${WRKSRC}|@dirrmtry ${OPENACSBASE:S/${PREFIX}\///}|' >> ${PLIST}
	@ ${FIND} ${WRKSRC}/etc -type d | \
		${SED} 's|${WRKSRC}/etc|@dirrm %%EXAMPLESDIR%%|' | \
		${SORT} -r >> ${PLIST}

do-install:
	@ ${ECHO} "Installing base files"
	@ ${MKDIR} ${OPENACSBASE}/etc
	@ ${TAR} -c -C ${WRKSRC} -f - ${BASE_INSTALL} | \
		${TAR} -x -C ${OPENACSBASE} -f -
	@ ${ECHO} "Installing examples"
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${TAR} -c -C ${WRKSRC}/etc -f - . | ${TAR} -x -C ${EXAMPLESDIR} -f -
	@ ${ECHO} "Installing sample configuration file"
	@ ${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-config.tcl ${EXAMPLESDIR}/config.tcl
	@ if ! [ -f ${OPENACSBASE}/etc/${PORTNAME}-config.tcl ]; then \
		${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-config.tcl ${OPENACSBASE}/etc/${PORTNAME}-config.tcl ; \
	  fi
.if !defined(NOPORTDOCS)
	@ ${ECHO} "Installing docs"
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog readme.txt license.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.for FILE in create_sampledb.sh adjust_pgsql_conf.sh
	@ ${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
