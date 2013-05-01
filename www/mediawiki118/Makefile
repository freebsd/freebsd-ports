# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.18.6
CATEGORIES=	www
MASTER_SITES=	http://dumps.wikimedia.org/mediawiki/${PORTVERSION:R}/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The wiki engine used by Wikipedia

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=2013-08-01

CONFLICTS=	mediawiki-1.19.* mediawiki-1.2[0-9].*

FETCH_ARGS=	-pr
NO_LATEST_LINK=	yes
USE_PHP=	ctype iconv mbstring pcre session xml zlib readline dom
IGNORE_WITH_PHP=	4
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/mediawiki
NO_BUILD=	yes

OPTIONS=	PGSQL "Use PostgreSQL (instead of MySQL)" off \
		LDAP "Use LDAP authentication" off \
		APC "Use pecl-APC" on \
		EACCEL "Use eAccelerator (instead of pecl-APC)" off \
		IMAGICK "Use ImageMagick" off

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
USE_MYSQL=	server
USE_PHP+=	mysql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_IMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/graphics/pecl-imagick
.endif

.if defined(WITH_APC) || defined(WITH_EACCEL)
.if defined(WITH_EACCEL)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/eaccelerator.so:${PORTSDIR}/www/eaccelerator
.else
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/apc.so:${PORTSDIR}/www/pecl-APC
.endif
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
