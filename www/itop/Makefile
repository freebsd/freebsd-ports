# $FreeBSD$

PORTNAME=	itop
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	iTop-${PORTVERSION}-2127

MAINTAINER=	olevole@olevole.ru
COMMENT=	Simple, web based IT Service Management tool

LICENSE=	AGPLv3

USES=		cpe zip
CPE_VENDOR=	combodo
USE_PHP=	ctype iconv mbstring pcre session xml zlib readline \
		dom simplexml hash json soap mcrypt filter zip

NO_BUILD=	yes

ITOPDIR=	${WWWDIR}/${PORTNAME}
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL LDAP
OPTIONS_DEFAULT=MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	client
USE_PHP+=	mysql mysqli
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	@${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
	${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	@${ECHO} @dir ${WWWDIR} >> ${TMPPLIST}
	@${ECHO_CMD} "@group" >> ${TMPPLIST}
	@${ECHO_CMD} "@owner" >> ${TMPPLIST}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -a ${WRKDIR}/web/ ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
