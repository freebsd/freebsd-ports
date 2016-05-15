# $FreeBSD$

PANDORA_VERSION=	6.0SP2
PANDORA_LICENSE=	GPLv2
PANDORA_LICENSE_FILE=	${WRKSRC}/COPYING

PANDORA_SPOOLDIR?=	/var/spool/pandora
PANDORA_LOGDIR?=	/var/log/pandora
PANDORA_ETCDIR?=	${PREFIX}/etc/pandora
PANDORA_HOMEDIR?=	${PANDORA_ETCDIR}/home

PANDORA_INSTALLER=	${PORTNAME}_installer
PANDORA_INSTALLER_ARGS=	--install

PORTVERSION=	${PANDORA_VERSION:C/SP/./}
# ignore nightly builds (*-YYYYMMDD)
PORTSCOUT=      limit:!.*-\d{8}$$

MASTER_SITES?=	SF/pandora/Pandora%20FMS%20${PANDORA_VERSION:C/((SP[0-9]*)*)$/\/\1/}Final/Tarball
.if ${PORTNAME} == "pandora_agent"
DISTNAME=	pandorafms_agent_unix-${PANDORA_VERSION}
.else
DISTNAME=	${PORTNAME:S/pandora_/pandorafms_/}-${PANDORA_VERSION}
.endif
DIST_SUBDIR=	pandora

NO_BUILD=	yes
NO_ARCH=	yes

USERS=		pandora
GROUPS=		pandora

ETCDIR?=	${PANDORA_ETCDIR}
SPOOLDIR?=	${PANDORA_SPOOLDIR}
LOGDIR?=	${PANDORA_LOGDIR}
HOMEDIR?=	${PANDORA_HOMEDIR}

PLIST_SUB+=	SPOOLDIR="${PANDORA_SPOOLDIR}" LOGDIR="${PANDORA_LOGDIR}" \
		USE_SPOOL_IN=${USE_SPOOL_IN} USE_SPOOL_OUT=${USE_SPOOL_OUT} \
		USE_LOGDIR=${USE_LOGDIR}
SUB_LIST+=	PANDORA_VERSION="${PANDORA_VERSION}"
PLIST=		${WRKDIR}/PLIST

PORTDOCS?=	AUTHORS

.if ${PORTNAME} == "pandora_server"
USE_LOGDIR=	""
USE_SPOOL_IN=	""
USE_SPOOL_OUT=	"@comment "
.elif ${PORTNAME} == "pandora_console"
USE_LOGDIR=	"@comment "
USE_SPOOL_IN=	""
USE_SPOOL_OUT=	"@comment "
PANDORA_INSTALLER=	pandora_console_install
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

do-install:
	@cd ${WRKSRC} && ${SH} ${PANDORA_INSTALLER} ${PANDORA_INSTALLER_ARGS}
