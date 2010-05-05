# New ports collection makefile for:	www/mediawiki
# Date created:				February 1st 2005
# Whom:	      				Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	mediawiki
PORTVERSION=	1.15.3
CATEGORIES=	www
MASTER_SITES=	http://download.wikimedia.org/mediawiki/1.15/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	The wiki engine used by Wikipedia

CONFLICTS=	mediawiki-1.[0-9].* mediawiki-1.1[0-46-9].*

USE_PHP=	iconv mbstring pcre session xml zlib readline dom
IGNORE_WITH_PHP=	4
WANT_PHP_WEB=	yes
MEDIAWIKIDIR?=	www/mediawiki

OPTIONS=	PGSQL "Use PostgreSQL (instead of MySQL)" off \
		LDAP "Use LDAP authentication" off \
		TEXVC "Use built-in TeX rendering" off \
		APC "Use pecl-APC" on \
		EACCEL "Use eAccelerator (instead of pecl-APC)" off \
		IMAGICK "Use ImageMagick" off

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
IGNORE_WITH_MYSQL=	323
USE_MYSQL=	yes
USE_PHP+=	mysql
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_TEXVC)
RUN_DEPENDS+=	latex:${PORTSDIR}/print/latex
BUILD_DEPENDS+=	ocaml:${PORTSDIR}/lang/ocaml

USE_GMAKE=yes
WITH_IMAGICK=yes
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

do-build:
.if defined(WITH_TEXVC)
	@(cd ${WRKSRC}/math && ${GMAKE})
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
