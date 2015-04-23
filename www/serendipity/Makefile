# Created by: babak@farrokhi.net
# $FreeBSD$

PORTNAME=	serendipity
PORTVERSION=	1.7.8
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/php-blog/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based weblog software

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/pear/File/Archive.php:${PORTSDIR}/archivers/pear-File_Archive

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
SERENDIPITY?=	www/${PORTNAME}
#PLIST_SUB+=	SERENDIPITY=${SERENDIPITY}
PLIST_SUB+=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
USE_PHP=	session pcre gd openssl mbstring iconv zlib xml
#SUB_LIST+=	SERENDIPITY=${SERENDIPITY}
SUB_FILES=	pkg-message
USES=		cpe tar:bzip2
CPE_VENDOR=	s9y

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE MAGICK
OPTIONS_DEFAULT=	MYSQL MAGICK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
. endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite
.endif

.if ${PORT_OPTIONS:MMAGICK}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

do-install:
	@-${MKDIR} ${STAGEDIR}${PREFIX}/${SERENDIPITY}
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/${SERENDIPITY}
	@(cd ${WRKSRC} && ${CP} -R * ${STAGEDIR}${PREFIX}/${SERENDIPITY}/ )

.include <bsd.port.mk>
