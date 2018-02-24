# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	1.11
CATEGORIES=	www
MASTER_SITES=	http://www.heuer.org/mod_auth_mysql/old/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}_${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	MySQL-based authentication module with VirtualHost support

LICENSE=	APACHE20

USES=		tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MYSQL=	yes
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

PORTDOCS=	INSTALL example_data.html htpasswd.sql

OPTIONS_DEFINE=	DOCS OPENSSL

OPENSSL_USES=		ssl
OPENSSL_VARS=	AP_EXTRAS+=-DMYSQL_USE_SSL

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
