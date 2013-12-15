# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

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

EXPIRATION_DATE=	2014-02-08
DEPRECATED=	Upstream site gone since 2011-03

RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_log_config-st.so:${PORTSDIR}/www/mod_log_config-st

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
USE_MYSQL=	yes

AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.include <bsd.port.mk>
