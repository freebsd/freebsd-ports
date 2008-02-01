# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.10.3
CATEGORIES=	www
MASTER_SITES=	http://download.wikimedia.org/mediawiki/1.10/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The wiki engine used by Wikipedia

CONFLICTS=	mediawiki-1.[0-9].* mediawiki-1.1[1-9].*

NO_BUILD=	yes
USE_MYSQL=	yes
IGNORE_WITH_MYSQL=	323
USE_PHP=	iconv mbstring pcre session xml zlib readline
IGNORE_WITH_PHP=	4
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/mediawiki

OPTIONS=	PGSQL "Use PostgreSQL instead of MySQL (not funtional)" off \
		LDAP "Use LDAP authentication" off

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
USE_PHP+=	mysql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

do-install:
	@${MKDIR} ${PREFIX}/${MEDIAWIKIDIR}
	${CP} -r ${WRKSRC}/ ${PREFIX}/${MEDIAWIKIDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MEDIAWIKIDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
		| ${SED} -ne 's,^${WRKSRC},${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
		| ${SED} -ne 's,^${WRKSRC},@dirrm ${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${SED} -e 's|%%MEDIAWIKIDIR%%|${PREFIX}/${MEDIAWIKIDIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
