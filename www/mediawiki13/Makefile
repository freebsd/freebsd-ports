# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.3.18
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wikipedia

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The wiki engine used by Wikipedia

CONFLICTS=	mediawiki-1.[0-24-9].*

NO_LATEST_LINK=	yes

NO_BUILD=	yes
USE_PHP=	iconv mbstring pcre session xml zlib imagick readline
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/data-dist/mediawiki

OPTIONS=	PGSQL "Use PostgreSQL instead of MySQL" off \
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

# Fix USE_PHP after bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.php.mk"

do-install:
	-${MKDIR} ${PREFIX}/${MEDIAWIKIDIR}
	@${CP} -r ${WRKSRC}/ ${PREFIX}/${MEDIAWIKIDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${MEDIAWIKIDIR}

post-install:
	@${FIND} ${WRKSRC}/${file} -not -type d \
	  | ${SED} -ne 's,^${WRKSRC},${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${FIND} -d ${WRKSRC}/${file} -type d \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${MEDIAWIKIDIR},p' >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/www/data-dist 2>/dev/null || true" >> ${TMPPLIST}
	@${SED} -e 's|%%MEDIAWIKIDIR%%|${PREFIX}/${MEDIAWIKIDIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
