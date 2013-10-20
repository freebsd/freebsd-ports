# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	yii
PORTVERSION=	1.1.14
DISTVERSIONSUFFIX=	.f0fee9
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance component-based PHP framework

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	yiisoft
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	f0fee9

WRKSRC=	${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-72100b6

NO_BUILD=	yes
USE_PHP=	pcre spl
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE REQPHP DOCS EXAMPLES
OPTIONS_DEFAULT=	REQPHP
REQPHP_DESC=	PHP dependencies required by plugins

PORTDOCS=	CHANGELOG LICENSE README UPGRADE

INSTALL_DIRS=	framework

PGSQL_RUN_DEPENDS=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREQPHP}
USE_PHP+=	apc dom gd mcrypt memcache pdo soap
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	pdo_sqlite
.endif

post-patch:
	@${SED} -i "" -e "s,dirname(__FILE__),'${DATADIR}/framework'," ${WRKSRC}/framework/yiic

do-install:
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "${INSTALL_DIRS}" ${STAGEDIR}${DATADIR})
	@${INSTALL_SCRIPT} ${WRKSRC}/framework/yiic ${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "demos requirements" ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
