# New ports collection makefile for:	mod_auth_cookie_mysql2
# Date created:				Sun Aug 8 2004
# Whom:					clement
#
# $FreeBSD$

PORTNAME=	mod_auth_cookie_mysql2
PORTVERSION=	0.9.a
CATEGORIES=	www
MASTER_SITES=	http://home.digithi.de/digithi/dev/mod_auth_cookie_mysql/
DISTNAME=	${PORTNAME}_0.9a
DIST_SUBDIR=	apache20

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows authentication against a MySQL database via a secure cookie

MAKE_JOBS_SAFE=  yes

USE_MYSQL=	YES
USE_APACHE=	20+

AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_EXTRAS=	-DMODULE_NAME=${SHORTMODNAME} -DMODULE_NAME_module=${SHORTMODNAME}_module
AP_INC=		`${LOCALBASE}/bin/mysql_config --include | ${SED} -e 's/^-I//'`
AP_LIB=		`${LOCALBASE}/bin/mysql_config --libs | ${SED} -e 's/^-L//'`
SRC_FILE=	mod_auth_cookie_sql2.c mod_auth_cookie_sql2_mysql.c

.include <bsd.port.mk>
