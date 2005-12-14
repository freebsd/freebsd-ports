# New ports collection makefile for:	serendipity
# Date created:		2005-DEC-13
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	serendipity
PORTVERSION=	0.9.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	php-blog

MAINTAINER=	babak@farrokhi.net
COMMENT=	PHP based weblog software

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
SERENDIPITY?=	www/${PORTNAME}
PLIST_SUB+=	SERENDIPITY=${SERENDIPITY}
USE_PHP=	session pcre gd openssl mbstring iconv zlib
SUB_LIST+=	SERENDIPITY=${SERENDIPITY}
SUB_FILES=	pkg-message

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend (PHP5)" off \
		MAGICK "Use ImageMagick Library" on

PORT_DBDIR?=	/var/db/ports
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}
OPTIONSFILE?=	${PORT_DBDIR}/${LATEST_LINK}/options

.if exists(${OPTIONSFILE})
.include "${OPTIONSFILE}"
.endif

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
. endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SQLITE)
USE_PHP+=	sqlite
.endif

.if !defined(WITHOUT_MAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

do-install:
	@-${MKDIR} ${PREFIX}/${SERENDIPITY}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SERENDIPITY}
	@(cd ${WRKSRC} && ${CP} -R * ${PREFIX}/${SERENDIPITY}/ )

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
