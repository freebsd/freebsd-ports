# New ports collection makefile for:   phprecipebook
# Date created:        27 September 2007
# Whom:                Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	phprecipebook
PORTVERSION=	2.39
CATEGORIES=	www deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION}

MAINTAINER=	mad@madpilot.net
COMMENT=	Small php webapp to manage your recipes

NO_BUILD=	yes
USE_PHP=	xml
WANT_PHP_WEB=	yes
RECIPEDIR?=	www/phprecipebook
SUB_FILES=	pkg-message

OPTIONS=	PGSQL "Use PostgreSQL instead of MySQL" off \

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
USE_PGSQL=	yes
.else
USE_PHP+=	mysql
USE_MYSQL=	yes
.endif

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

do-install:
	@${MV} ${WRKSRC}/custom_inc.php ${WRKSRC}/custom_inc.php.sample
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PREFIX}/${RECIPEDIR}
	@if [ ! -f ${PREFIX}/${RECIPEDIR}/custom_inc.php ]; then \
		${CP} ${PREFIX}/${RECIPEDIR}/custom_inc.php.sample \
		${PREFIX}/${RECIPEDIR}/custom_inc.php ; fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${RECIPEDIR}

post-install:
	@${ECHO} "@unexec if cmp -s %D/${RECIPEDIR}/custom_inc.php.sample \
		%D/${RECIPEDIR}/custom_inc.php; \
		then rm -f %D/${RECIPEDIR}/custom_inc.php; fi" >> ${TMPPLIST}
	@${ECHO} "${RECIPEDIR}/custom_inc.php.sample" >> ${TMPPLIST}
	@${ECHO} "@exec if [ ! -f %D/${RECIPEDIR}/custom_inc.php ] ; \
		then cp -p %D/%F %B/custom_inc.php; fi" >> ${TMPPLIST}
	@${ECHO} "@exec mkdir -p %D/${RECIPEDIR}/modules/settings" >> ${TMPPLIST}
	@${FIND} ${WRKSRC}/${file} -not -type d -not -name 'custom_inc.php*' \
		| ${SED} -ne 's,^${WRKSRC},${RECIPEDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
		| ${SED} -ne 's,^${WRKSRC},@dirrm ${RECIPEDIR},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${RECIPEDIR}' >> ${TMPPLIST}
	@${SED} -e 's|%%RECIPEDIR%%|${PREFIX}/${RECIPEDIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
