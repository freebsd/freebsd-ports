# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	yii
PORTVERSION=	1.1.13
DISTVERSIONSUFFIX=	.e9e4a0
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE \
		SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A high-performance component-based PHP framework

LICENSE=	BSD

NO_BUILD=	yes
USE_PHP=	pcre spl
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE REQPHP DOCS EXAMPLES
OPTIONS_DEFAULT=	REQPHP
REQPHP_DESC=	PHP dependencies required by plugins

PORTDOCS=	CHANGELOG LICENSE README UPGRADE

INSTALL_DIRS=	framework

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREQPHP}
USE_PHP+=	apc dom gd mcrypt memcache pdo soap
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

post-patch:
	@${SED} -i "" -e "s,dirname(__FILE__),'${DATADIR}/framework'," ${WRKSRC}/framework/yiic

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${INSTALL_DIRS}" ${DATADIR})
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${DATADIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${DATADIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
	@${INSTALL_SCRIPT} ${WRKSRC}/framework/yiic ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "demos requirements" ${EXAMPLESDIR})
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${EXAMPLESDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} \
		${EXAMPLESDIR:S|^${PREFIX}/|%D/|}' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type f -print0 | \
		${XARGS} -0 ${CHMOD} 644' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${ECHO_CMD} '@exec ${FIND} ${EXAMPLESDIR} -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755' >> ${TMPPLIST}
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
