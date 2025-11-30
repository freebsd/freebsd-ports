PORTNAME=	serendipity
PORTVERSION=	2.5.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP based weblog software
WWW=		https://www.s9y.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php shebangfix tar:bzip2

USE_GITHUB=		yes
GH_ACCOUNT=		s9y
GH_PROJECT=		Serendipity

NO_BUILD=	YES
SERENDIPITY?=	www/${PORTNAME}
PLIST_SUB+=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
USE_PHP=	session gd mbstring iconv zlib xml
SUB_FILES=	pkg-message
CPE_VENDOR=	s9y

SHEBANG_FILES=	lang/*.sh \
		lang/UTF-8/*.sh \
		bundled-libs/smarty/smarty/*.sh

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE MAGICK
OPTIONS_DEFAULT=	MYSQL MAGICK

MYSQL_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite3
MAGICK_USES=	magick:7,run

do-install:
	@-${MKDIR} ${STAGEDIR}${PREFIX}/${SERENDIPITY}
	@${CHMOD} 755 ${STAGEDIR}${PREFIX}/${SERENDIPITY}
	@(cd ${WRKSRC} && ${CP} -R * ${STAGEDIR}${PREFIX}/${SERENDIPITY}/ )

.include <bsd.port.mk>
