# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.3.12
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wikipedia

MAINTAINER=	tux@pinguru.net
COMMENT=	The wiki enginge used by Wikipedia

NO_BUILD=	yes
USE_PHP=	iconv mbstring pcre session xml zlib imagick readline
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/data-dist/mediawiki

OPTIONS=	PGSQL "Use PostgreSQL instead of MySQL" off \
		LDAP "Use LDAP authentication" off

PORT_DBDIR?=	/var/db/ports
NO_LATEST_LINK=	yes
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
USE_PHP+=	mysql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

do-install:
	-${MKDIR} ${PREFIX}/${MEDIAWIKIDIR}
	@${CP} -r ${WRKSRC}/ ${PREFIX}/${MEDIAWIKIDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MEDIAWIKIDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${SED} -e 's|%%MEDIAWIKIDIR%%|${PREFIX}/${MEDIAWIKIDIR}|' ${PKGMESSAGE}

.include <bsd.port.mk>
