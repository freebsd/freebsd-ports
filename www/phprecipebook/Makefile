# $FreeBSD$

PORTNAME=	phprecipebook
PORTVERSION=	3.01
CATEGORIES=	www deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20%28stable%29/${PORTVERSION:C/\..*//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Small php webapp to manage your recipes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.TXT

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PHP=	xml
WANT_PHP_WEB=	yes
RECIPEDIR?=	www/phprecipebook
SUB_FILES=	pkg-message

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
USE_MYSQL=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
USE_PGSQL=	yes
.endif

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

do-install:
	@${CP} ${WRKSRC}/custom_inc.php ${WRKSRC}/custom_inc.php.sample
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

.include <bsd.port.mk>
