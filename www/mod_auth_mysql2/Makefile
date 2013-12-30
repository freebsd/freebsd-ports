# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_auth_mysql
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.heuer.org/mod_auth_mysql/old/
PKGNAMESUFFIX=	2
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL-based authentication module with VirtualHost support

LICENSE=	APACHE20

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_MYSQL=	yes
USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
AP_EXTRAS+=	-DMYSQL_USE_SSL
.endif

PORTDOCS=	INSTALL example_data.html htpasswd.sql

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
