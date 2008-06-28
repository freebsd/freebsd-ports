# New ports collection makefile for:	serendipity
# Date created:		2005-DEC-13
# Whom:			babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	serendipity-devel
PORTVERSION=	1.0.${SNAPSHOT}
CATEGORIES=	www
MASTER_SITES=	http://www.s9y.org/snapshots/
DISTNAME=	s9y_${SNAPSHOT}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	PHP based weblog software

RUN_DEPENDS=	${LOCALBASE}/share/pear/File/Archive.php:${PORTSDIR}/archivers/pear-File_Archive

SNAPSHOT=	200806272342
WRKSRC=		${WRKDIR}/serendipity-nightly
NO_BUILD=	YES
SERENDIPITY?=	www/serendipity
PLIST_SUB+=	SERENDIPITY=${SERENDIPITY}
USE_PHP=	session pcre gd openssl mbstring iconv zlib xml
SUB_LIST+=	SERENDIPITY=${SERENDIPITY}
SUB_FILES=	pkg-message

CONFLICTS=	serendipity-1.*

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
