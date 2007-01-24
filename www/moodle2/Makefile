# New ports collection makefile for:	moodle
# Date created:				30 September 2005
# Whom:					Javier Martin Rueda <jmrueda@diatel.upm.es>
#
# $FreeBSD$
#

PORTNAME=	moodle
PORTVERSION=	1.7.1
CATEGORIES=	www
MASTER_SITES=	http://download.moodle.org/stable17/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmrueda@diatel.upm.es
COMMENT=	Course management system based on social constructionism

USE_PHP=	session gd pcre
WRKSRC=		${WRKDIR}/moodle

.if defined(WITH_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.include <bsd.port.pre.mk>

NO_BUILD=	yes
PLIST=		${WRKDIR}/plist
SUB_FILES=	pkg-message
SUB_LIST=	MOODLEDIR=${MOODLEDIR} \
		MOODLEDATADIR=${MOODLEDATADIR}

MOODLEDIR?=	www/moodle
MOODLEDATADIR?=	www/moodledata

pre-everything::
	@${ECHO_CMD} "===> You can use the following options:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "o WITH_MYSQL - Use a MySQL database"
	@${ECHO_CMD} "o WITH_PGSQL - Use a pgSQL database"
	@${ECHO_CMD} "o WITH_LDAP  - Ensure your PHP has ldap extension"
	@${ECHO_CMD} ""

pre-install:
	@${FIND} -s -d ${WRKSRC} -type f | ${SED} "s?${WRKSRC}?${MOODLEDIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC} -type d  | ${SED} "s?${WRKSRC}?@dirrm ${MOODLEDIR}?g" >> ${PLIST}
	@${ECHO} @dirrm ${MOODLEDATADIR} >> ${PLIST}

do-install:
	${INSTALL_DATA} -d ${PREFIX}/${MOODLEDIR}
	${CP} -Rn ${WRKSRC}/* ${PREFIX}/${MOODLEDIR}
	${FIND} ${PREFIX}/${MOODLEDIR} -type d -exec ${CHMOD} a+x {} \;
	${MKDIR} ${PREFIX}/${MOODLEDATADIR}
	${CHOWN} www ${PREFIX}/${MOODLEDATADIR}
	${CHMOD} 755 ${PREFIX}/${MOODLEDATADIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
