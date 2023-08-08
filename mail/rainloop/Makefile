PORTNAME=	rainloop
DISTVERSIONPREFIX=	legacy-
DISTVERSION=	1.17.0
CATEGORIES=	mail www
MASTER_SITES=	https://github.com/RainLoop/rainloop-webmail/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern and interactive webmail
WWW=		https://rainloop.net/

LICENSE=	MIT

USES=		php:web,flavors zip
USE_PHP=	curl dom iconv simplexml xml zlib

NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes

PLIST_SUB=	VER="${PORTVERSION}" \
		WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

OPTIONS_DEFAULT=	SQLITE
OPTIONS_RADIO=		DB
OPTIONS_RADIO_DB=	MYSQL PGSQL SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

post-patch:
	${REINPLACE_CMD} 's/__USE_SINGLE_LINE_AUTH_PLAIN_COMMAND = false/__USE_SINGLE_LINE_AUTH_PLAIN_COMMAND = true/' \
		${WRKSRC}/rainloop/v/${PORTVERSION}/app/libraries/MailSo/Smtp/SmtpClient.php
	${RM} ${WRKSRC}/rainloop/v/${PORTVERSION}/app/libraries/MailSo/Smtp/SmtpClient.php.bak

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${STAGEDIR}${WWWDIR}/data
	${INSTALL_DATA} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} rainloop ${STAGEDIR}${WWWDIR})
# Prune empty dirs
	@${FIND} ${STAGEDIR}${WWWDIR}/${PORTNAME}/v/${PORTVERSION} -type d -empty -delete

.include <bsd.port.mk>
