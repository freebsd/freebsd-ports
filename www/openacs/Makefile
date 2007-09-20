# New ports collection makefile for:    openACS
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <aldert@nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME?=	openacs
DISTVERSION?=	5-3-2
CATEGORIES=	www
MASTER_SITES?=	http://openacs.org/projects/openacs/download/download/
EXTRACT_SUFX?=	.tgz?revision_id=1098887

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	A modular web application platform for communities

AOLSERVERBASE?=	${LOCALBASE}/aolserver
TCLLIB_VER?=	1.10
RUN_DEPENDS+=	${AOLSERVERBASE}/bin/nscache.so:${PORTSDIR}/www/aolserver-nscache \
		${AOLSERVERBASE}/bin/nsopenssl.so:${PORTSDIR}/security/aolserver-nsopenssl \
		${AOLSERVERBASE}/bin/nssha1.so:${PORTSDIR}/security/aolserver-nssha1 \
		${AOLSERVERBASE}/bin/nspostgres.so:${PORTSDIR}/databases/aolserver-nspostgres \
		${AOLSERVERBASE}/modules/tcl/xotcl.tcl:${PORTSDIR}/www/aolserver-xotcl \
		${LOCALBASE}/lib/tcllib${TCLLIB_VER}/pkgIndex.tcl:${PORTSDIR}/devel/tcllib \
		${LOCALBASE}/lib/tdomConfig.sh:${PORTSDIR}/www/tdom

USE_RC_SUBR?=	${PORTNAME}
NO_BUILD=	yes

OPENACS_USER?=	${PORTNAME}
OPENACS_DB?=	${PORTNAME}
OPENACS_GROUP?=	www
PGUSER?=	pgsql
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

OPTIONS=	EXAMPLES "Install various example files" on \
		TCLTHREAD "Depend on tclthread" on \
		TCLWEBTEST "Depend on tclwebteset" on

.include <bsd.port.pre.mk>

SUB_LIST+=	OPENACS_USER=${OPENACS_USER} OPENACS_GROUP=${OPENACS_GROUP} \
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
		-e 's|/var/lib/aolserver/$${server}|${OPENACSBASE}|' \
		-e 's|/usr/local/aolserver|${AOLSERVERBASE}|' \
		${WRKSRC}/etc/config.tcl > ${WRKDIR}/openacs-config.tcl
pre-install:
	@ ${ECHO} "Generating plist"
	@ ${FIND} ${WRKSRC} ! -type d ! -path '${WRKSRC}/etc*' \
		! -path '${WRKSRC}/readme.txt' ! -path '${WRKSRC}/license.txt' \
		! -path '${WRKSRC}/ChangeLog' | \
		${SED} 's|${WRKSRC}|${OPENACSBASE:S/${PREFIX}\///}|' > ${PLIST}
	@ ${ECHO} ${OPENACSBASE:S/${PREFIX}\///}/etc/${PORTNAME}-config.tcl >> ${PLIST}
	@ ${ECHO} @dirrm ${OPENACSBASE:S/${PREFIX}\///}/etc >> ${PLIST}
	@ ${FIND} ${WRKSRC} -type d ! -path '${WRKSRC}/etc*' | \
		${SORT} -r | \
		${SED} 's|${WRKSRC}|@dirrmtry ${OPENACSBASE:S/${PREFIX}\///}|' >> ${PLIST}
.if defined(WITH_EXAMPLES)
	@ ${FIND} ${WRKSRC}/etc ! -type d | \
		${SED} 's|${WRKSRC}/etc|%%EXAMPLESDIR%%|' >> ${PLIST}
	@ ${FIND} ${WRKSRC}/etc -type d | \
		${SED} 's|${WRKSRC}/etc|@dirrm %%EXAMPLESDIR%%|' | \
		${SORT} -r >> ${PLIST}
.endif

do-install:
	@ ${ECHO} "Installing base files"
	@ ${MKDIR} ${OPENACSBASE}/etc
	@ ${TAR} -c -C ${WRKSRC} -f - ${BASE_INSTALL} | \
		${TAR} -x -C ${OPENACSBASE} -f -
.if defined(WITH_EXAMPLES)
	@ ${ECHO} "Installing examples"
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${TAR} -c -C ${WRKSRC}/etc -f - . | ${TAR} -x -C ${EXAMPLESDIR} -f -
.endif
	@ ${ECHO} "Installing sample configuration file"
	@ ${INSTALL_DATA} ${WRKDIR}/openacs-config.tcl ${OPENACSBASE}/etc/${PORTNAME}-config.tcl
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
