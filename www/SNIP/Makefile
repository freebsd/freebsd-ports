PORTNAME=	SNIP
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	www

MAINTAINER=	ek@purplehat.org
COMMENT=	SNIP is a powerful, simple, and easy to use Open-Source PHP Pastebin
WWW=		https://github.com/MercanoGlobal/SNIP

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:web

USE_GITHUB=	yes
GH_ACCOUNT=	MercanoGlobal

USE_PHP=	ctype filter gd session

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message
PLIST_SUB+=	WWWGRP="${WWWGRP}" \
		WWWOWN="${WWWOWN}"

OPTIONS_DEFAULT=	MYSQLI
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQLI PGSQL SQLITE

MYSQLI_DESC=	Install MySQLi Support for PHP

MYSQLI_USE=	PHP=mysqli
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pgsql
SQLITE_USES=	sqlite
SQLITE_USE=	PHP=sqlite3

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${FIND} ${STAGEDIR}${WWWDIR} -type f -iname "*.orig" -delete
	${INSTALL_DATA} ${STAGEDIR}${WWWDIR}/application/config/snip.php.dist ${STAGEDIR}${ETCDIR}/snip.php.sample
	${LN} -sf ${ETCDIR}/snip.php ${STAGEDIR}${WWWDIR}/application/config/

post-install:
	@${ECHO_CMD} "@owner ${WWWOWN}" >> ${TMPPLIST}
	@${ECHO_CMD} "@group ${WWWGRP}" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${ETCDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${ETCDIR}#${ETCDIR_REL}#' | \
		${SED} -E -e '/sample$$/ s#^#@sample(,,0640) #;' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/snip.php(\.dist)?/ s#^#@(,,0640) #;' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -type d -exec echo "@dir {}" \; | ${SORT} | \
		${SED} -e 's#^@dir ${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
