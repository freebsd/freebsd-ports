# New ports collection makefile for:	mod_mod_mysql
# Date created:				Sun May 2 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_mysql
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	www
# Original location: http://bitbrook.de/software/mod_log_mysql/mod_log_mysql.c
# Please handle update requests with care!
# sheepkiller was hacked and not cleaned over a long periode.
# (First notice 2011-03 not cleaned until 2011-07)
# Provide distfile now from LOCAL
#MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
MASTER_SITES=	LOCAL/ohauer
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows Apache 2 to log to a MySQL database

RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_log_config-st.so:${PORTSDIR}/www/mod_log_config-st

MAKE_JOBS_SAFE=	yes

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
USE_MYSQL=	YES

AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.include <bsd.port.mk>
