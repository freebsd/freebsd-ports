# New ports collection makefile for:    openACS
# Date created:         July 2005
# Whom:                 Aldert Nooitgedagt <aldert@nooitgedagt.net>
#
# $FreeBSD$
#

PORTNAME?=	openacs
PORTVERSION?=	5.3.0
PORTREVISION?=	1
CATEGORIES=	www
MASTER_SITES?=	http://openacs.org/projects/openacs/download/download/
EXTRACT_SUFX?=	.tgz?revision_id=583060

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	A modular web application platform for high traffic communities

AOLSERVERBASE?=	${LOCALBASE}/aolserver
RUN_DEPENDS=	${AOLSERVERBASE}/bin/nscache.so:${PORTSDIR}/www/aolserver-nscache \
		${AOLSERVERBASE}/bin/nsopenssl.so:${PORTSDIR}/security/aolserver-nsopenssl \
		${AOLSERVERBASE}/bin/nssha1.so:${PORTSDIR}/security/aolserver-nssha1 \
		${AOLSERVERBASE}/bin/nspostgres.so:${PORTSDIR}/databases/aolserver-nspostgres \
		${LOCALBASE}/lib/tdomConfig.sh:${PORTSDIR}/www/tdom

USE_RC_SUBR?=	${PORTNAME}
NO_BUILD=	yes

OPENACS_USER?=	${PORTNAME}
OPENACS_DB?=	${PORTNAME}
OPENACS_GROUP?=	www
PGUSER?=	pgsql
OPENACSBASE?=	${TARGETDIR}/openacs
OPENACSNAME?=	OpenACS

BASE_INSTALL?=	bin content-repository-content-files log packages tcl www
PLIST=		${WRKDIR}/plist.tmp
SUB_LIST+=	OPENACS_USER=${OPENACS_USER} OPENACS_GROUP=${OPENACS_GROUP} \
		OPENACSBASE=${OPENACSBASE} OPENACS_DB=${OPENACS_DB} \
		PGUSER=${PGUSER} AOLSERVERBASE=${AOLSERVERBASE} \
		PORTNAME=${PORTNAME} OPENACSNAME=${OPENACSNAME}

SUB_FILES+=	pkg-install pkg-deinstall pkg-message openacs dotlrn create_sampledb.sh
PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog readme.txt license.txt
.endif

OPTIONS=	EXAMPLES "Install various example files" on

.include <bsd.port.pre.mk>

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
		${SED} 's|${WRKSRC}|${OPENACSBASE:S/${TARGETDIR}\///}|' > ${PLIST}
	@ ${ECHO} ${OPENACSBASE:S/${TARGETDIR}\///}/etc/${PORTNAME}-config.tcl >> ${PLIST}
	@ ${ECHO} @dirrm ${OPENACSBASE:S/${TARGETDIR}\///}/etc >> ${PLIST}
	@ ${FIND} ${WRKSRC} -type d ! -path '${WRKSRC}/etc*' | \
		${SORT} -r | \
		${SED} 's|${WRKSRC}|@dirrmtry ${OPENACSBASE:S/${TARGETDIR}\///}|' >> ${PLIST}
.if defined(WITH_EXAMPLES)
	@ ${FIND} ${WRKSRC}/etc ! -type d | \
		${SED} 's|${WRKSRC}/etc|%%EXAMPLESDIR%%|' >> ${PLIST}
	@ ${ECHO} %%EXAMPLESDIR%%/create_sampledb.sh >> ${PLIST}
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
	@ ${INSTALL_SCRIPT} ${WRKDIR}/create_sampledb.sh ${EXAMPLESDIR}
.endif
	@ ${ECHO} "Installing sample configuration file"
	@ ${INSTALL_DATA} ${WRKDIR}/openacs-config.tcl ${OPENACSBASE}/etc/${PORTNAME}-config.tcl
.if !defined(NOPORTDOCS)
	@ ${ECHO} "Installing docs"
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
