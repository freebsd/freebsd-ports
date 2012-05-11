# $FreeBSD$

PANDORA_VERSION=	4.0.1
PANDORA_LICENSE=	GPLv2
PANDORA_LICENSE_FILE=	${WRKSRC}/COPYING

PANDORA_SPOOLDIR?=	/var/spool/pandora
PANDORA_LOGDIR?=	/var/log/pandora
PANDORA_ETCDIR?=	${PREFIX}/etc/pandora
PANDORA_HOMEDIR?=	${PANDORA_ETCDIR}/home

MASTER_SITES?=	SF/pandora/Pandora%20FMS%20${PANDORA_VERSION}/Tarball
.if ${PORTNAME} == "pandora_agent"
DISTNAME=	pandorafms_agent_unix-${PORTVERSION}
.else
DISTNAME=	${PORTNAME:S/pandora_/pandorafms_/}-${PORTVERSION}
.endif
DIST_SUBDIR=	pandora

NO_BUILD?=	yes

USERS=		pandora
GROUPS=		pandora

ETCDIR?=	${PANDORA_ETCDIR}
SPOOLDIR?=	${PANDORA_SPOOLDIR}
LOGDIR?=	${PANDORA_LOGDIR}
HOMEDIR?=	${PANDORA_HOMEDIR}
HOMEDIR_REL=	${HOMEDIR:S,^${PREFIX}/,,}

PLIST_SUB+=	SPOOLDIR="${PANDORA_SPOOLDIR}" LOGDIR="${PANDORA_LOGDIR}" \
		USE_SPOOL_IN=${USE_SPOOL_IN} USE_SPOOL_OUT=${USE_SPOOL_OUT} \
		USE_LOGDIR=${USE_LOGDIR}
PLIST=		${WRKDIR}/PLIST

PORTDOCS?=	AUTHORS ChangeLog

.if ${PORTNAME} == "pandora_server"
USE_LOGDIR=	""
USE_SPOOL_IN=	""
USE_SPOOL_OUT=	"@comment "
.elif ${PORTNAME} == "pandora_console"
USE_LOGDIR=	"@comment "
USE_SPOOL_IN=	""
USE_SPOOL_OUT=	"@comment "
.elif ${PORTNAME} == "pandora_agent"
USE_LOGDIR=	""
USE_SPOOL_IN=	"@comment "
USE_SPOOL_OUT=	""
.endif

.if ${PORTNAME} == "pandora_agent"
post-extract:
	@${MV} ${WRKDIR}/unix ${WRKSRC}
.else
post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}
.endif

pre-install:
	@${CAT} ${PKGDIR}/../pandorafms_server/pkg-plist.spool > ${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >> ${PLIST}
	@${ECHO_MSG} '@exec [ -e "%D/${ETCDIR_REL}" ] || ${MKDIR} "%D/${ETCDIR_REL}"' >> ${PLIST}
	@${ECHO_MSG} '@exec if [ -e "%D/${HOMEDIR_REL}" ];then ${TRUE}; else ${MKDIR} "%D/${HOMEDIR_REL}"; ${CHOWN} ${USER}:${GROUP} "%D/${HOMEDIR_REL}";fi' >> ${PLIST}
	@${ECHO_MSG} '@unexec ${RMDIR} "%D/${HOMEDIR_REL}" 2>/dev/null || ${TRUE}' >> ${PLIST}
	@${ECHO_MSG} '@unexec ${RMDIR} "%D/${ETCDIR_REL}" 2>/dev/null || ${TRUE}' >> ${PLIST}
