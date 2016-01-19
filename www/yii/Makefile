# Created by: Yi-Jheng Lin <yzlin@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	yii
PORTVERSION=	1.1.17
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-performance component-based PHP framework

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	yiisoft

NO_BUILD=	yes
USES=		cpe
CPE_PRODUCT=	yiiframework
USE_PHP=	pcre spl
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE REQPHP DOCS EXAMPLES
OPTIONS_DEFAULT=	REQPHP
REQPHP_DESC=	PHP dependencies required by plugins

PORTDOCS=	CHANGELOG LICENSE README UPGRADE

INSTALL_DIRS=	framework

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
REQPHP_USE=	PHP=dom,gd,mcrypt,memcache,pdo,soap
SQLITE_USE=	PHP=pdo_sqlite

post-patch:
	@${SED} -i "" -e "s,dirname(__FILE__),'${DATADIR}/framework'," ${WRKSRC}/framework/yiic

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${INSTALL_DIRS}" ${STAGEDIR}${DATADIR})
	${INSTALL_SCRIPT} ${WRKSRC}/framework/yiic ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "demos requirements" ${STAGEDIR}${EXAMPLESDIR})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
