# New ports collection makefile for:	mod_mod_mysql
# Date created:				Sun May 2 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_mysql
PORTVERSION=	1.0
CATEGORIES=	www
# Original location: http://bitbrook.de/software/mod_log_mysql/mod_log_mysql.c
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache 2 to log to a MySQL database

RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_log_config-st.so:${PORTSDIR}/www/mod_log_config-st

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
USE_MYSQL=	YES

AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
.include <bsd.port.post.mk>
