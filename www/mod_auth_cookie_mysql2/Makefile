# Created by: clement
# $FreeBSD$

PORTNAME=	mod_auth_cookie_mysql2
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://home.digithi.de/digithi/dev/mod_auth_cookie_mysql/
DISTNAME=	${PORTNAME}_1.0
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows authentication against MySQL database via secure cookie

USE_MYSQL=	yes
USES=		apache:2.2+

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS=	-DMODULE_NAME=${SHORTMODNAME} -DMODULE_NAME_module=${SHORTMODNAME}_module
AP_INC=		${LOCALBASE}/include/mysql
AP_LIB=		${LOCALBASE}/lib/mysql -lmysqlclient
SRC_FILE=	mod_auth_cookie_sql2.c mod_auth_cookie_sql2_mysql.c

.include <bsd.port.mk>
