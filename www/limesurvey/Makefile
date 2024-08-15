PORTNAME=	limesurvey
PORTVERSION=	6.6.1
CATEGORIES=	www
MASTER_SITES=	http://download.limesurvey.org/latest-master/ \
		LOCAL/flo
DISTNAME=	${PORTNAME}${PORTVERSION}+240806

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP-based survey building and runing system
WWW=		https://www.limesurvey.org/

LICENSE=	GPLv2

USES=		cpe php:web zip

OPTIONS_DEFINE=		GD IMAP LDAP PGSQL
OPTIONS_DEFAULT=	GD

PGSQL_DESC=	Use PostgreSQL (instead of MySQL)
GD_DESC=	Install PHP gd extension
LDAP_DESC=	Install PHP LDAP extension
IMAP_DESC=	Install PHP IMAP extension

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP=	pdo_pgsql
.else
# server is not necessary on this host.
USE_PHP=	pdo_mysql
.endif
.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
.endif
.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif
.if ${PORT_OPTIONS:MIMAP}
USE_PHP+=	imap
.endif
USE_PHP+=	ctype dom iconv mbstring session \
		simplexml xmlwriter zip zlib

WWWDOCROOT?=		www
PHPSURVEYORURL?=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PHPSURVEYORDIR="${PHPSURVEYORDIR}" \
		PHPSURVEYORURL="${PHPSURVEYORURL}"

PHPSURVEYORDIR=	${WWWDOCROOT}/${PHPSURVEYORURL}

do-install:
	${MKDIR} "${STAGEDIR}${WWWDIR}"
	@cd "${WRKSRC}" && ${COPYTREE_SHARE} . "${STAGEDIR}${WWWDIR}"
	${MKDIR} "${STAGEDIR}${WWWDIR}"/tmp
	${CHMOD} 755 "${STAGEDIR}${WWWDIR}"/tmp
	${CHMOD} 755 "${STAGEDIR}${WWWDIR}"/upload
	${CHMOD} -R go-w "${STAGEDIR}${WWWDIR}"/admin

post-install:
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${FIND} -s -d ${STAGEDIR}${WWWDIR}/admin -type f -print | \
		${SED} -e "s#${STAGEDIR}${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${STAGEDIR}${WWWDIR}/admin -type d -print | \
		${SED} -E -e "s#${STAGEDIR}${PREFIX}/#@dir #g" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${FIND} -s -d ${STAGEDIR}${WWWDIR} ! -path "${STAGEDIR}${WWWDIR}/admin/*" -type f -print | \
		${SED} -e "s#${STAGEDIR}${PREFIX}/##g" >> ${TMPPLIST}
	@${FIND} -s -d ${STAGEDIR}${WWWDIR} -type d ! -path "${STAGEDIR}${WWWDIR}/admin*" -print | \
		${SED} -E -e "s#${STAGEDIR}${PREFIX}/#@dir #g" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
