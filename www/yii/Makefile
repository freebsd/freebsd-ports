# New ports collection makefile for:	yii
# Date created:		2009-03-27
# Whom:			Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	yii
PORTVERSION=	1.0.9
DISTVERSIONSUFFIX=	.r1396
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		SF

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	A high-performance component-based PHP framework

NO_BUILD=	yes
USE_PHP=	pcre spl
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=	4

SUB_FILES=	pkg-message

OPTIONS=	MYSQL "Install MySQL PDO support" Off \
		PGSQL "Install PostgreSQL PDO support" Off \
		SQLITE "Install SQLite v3 PDO support" Off \
		REQPHP "Install PHP dependencies required by plugins" On

PORTDOCS=	CHANGELOG LICENSE README UPGRADE

INSTALL_DIRS=	framework

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_REQPHP)
USE_PHP+=	apc dom gd mcrypt memcache pdo soap
.endif

.if defined(WITH_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if defined(WITH_SQLITE)
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
.if !defined(NOPORTEXAMPLES)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
