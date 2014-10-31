# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_mysql
PORTVERSION=	1.04
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://bsdforge.com/projects/source/www/mod_log_mysql/
DIST_SUBDIR=	apache2

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Allows Apache 2.2.x to log to a MySQL database

LICENSE=	PUBLIC_DOMAIN APACHE11
LICENSE_COMB=	multi
LICENSE_NAME_PUBLIC_DOMAIN=	Public Domain
LICENSE_TEXT_PUBLIC_DOMAIN=	mod_log_mysql.c is in the Public Domain as of 2003.10.23.
LICENSE_PERMS_PUBLIC_DOMAIN=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:xz
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_log_config-st.so:${PORTSDIR}/www/mod_log_config-st

USE_APACHE=	22+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
USE_MYSQL=	yes

AP_INC+=	${LOCALBASE}/include/mysql
AP_LIB+=	${LOCALBASE}/lib/mysql -lmysqlclient

.include <bsd.port.mk>
