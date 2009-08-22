# New ports collection makefile for:	serendipity
# Date created:		2005-DEC-13
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	serendipity
PORTVERSION=	1.4.1
CATEGORIES=	www
MASTER_SITES=	SF/php-blog/${PORTNAME}/${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP based weblog software

RUN_DEPENDS=	${LOCALBASE}/share/pear/File/Archive.php:${PORTSDIR}/archivers/pear-File_Archive

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
SERENDIPITY?=	www/${PORTNAME}
PLIST_SUB+=	SERENDIPITY=${SERENDIPITY}
USE_PHP=	session pcre gd openssl mbstring iconv zlib xml
SUB_LIST+=	SERENDIPITY=${SERENDIPITY}
SUB_FILES=	pkg-message
USE_BZIP2=	YES

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend (php5 only)" off \
		MAGICK "Use ImageMagick Library" on

.include <bsd.port.pre.mk>

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
	@${CHMOD} 755 ${PREFIX}/${SERENDIPITY}
	@(cd ${WRKSRC} && ${CP} -R * ${PREFIX}/${SERENDIPITY}/ )
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${SERENDIPITY}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
