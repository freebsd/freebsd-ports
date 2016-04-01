# Created by: gahr
# $FreeBSD$

PORTNAME=	opensmtpd-extras
PORTVERSION=	201602042118
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Addons for OpenSMTPD

LICENSE=	ISCL

OPTIONS_GROUP=		TABLE
OPTIONS_GROUP_TABLE=	LDAP MYSQL PASSWD PGSQL PYTHON REDIS SMAP SQLITE
OPTIONS_DEFAULT=	LDAP MYSQL PASSWD PGSQL PYTHON REDIS SMAP SQLITE

PASSWD_DESC=	passwd(5) table support
SMAP_DESC=	Socketmap protocol support

OPTIONS_SUB=	yes

LIB_DEPENDS=	libevent.so:devel/libevent2
RUN_DEPENDS=	${LOCALBASE}/sbin/smtpctl:mail/opensmtpd

USES=		autoreconf libtool pkgconfig
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	man/man3/filter_api.3.gz
INSTALL_DIR=	libexec/opensmtpd

#
# Tables
#
MYSQL_CONFIGURE_WITH=	table-mysql
MYSQL_VARS=		USE_MYSQL=client \
			LDFLAGS+=-L${LOCALBASE}/lib/mysql \
			PLIST_FILES+=${INSTALL_DIR}/table-mysql

PASSWD_CONFIGURE_WITH=	table-passwd
PASSWD_VARS=		PLIST_FILES+=${INSTALL_DIR}/table-passwd \
			PLIST_FILES+=man/man5/table-passwd.5.gz

PGSQL_CONFIGURE_WITH= 	table-postgres
PGSQL_USES=		pgsql
PGSQL_VARS=		PLIST_FILES+=${INSTALL_DIR}/table-postgres

PYTHON_CONFIGURE_WITH=	table-python python-type=${PYTHON_VERSION}
PYTHON_USES=		python
PYTHON_VARS=		PLIST_FILES+=${INSTALL_DIR}/table-python

REDIS_CONFIGURE_WITH=	table-redis
REDIS_CONFIGURE_ENV=	REDIS_CONFIG=${LOCALBASE}/bin/pkgconf
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_VARS=		CFLAGS+=-I${LOCALBASE}/include/hiredis \
			PLIST_FILES+=${INSTALL_DIR}/table-redis \
			PLIST_FILES+=man/man5/table-redis.5.gz

SMAP_CONFIGURE_WITH=	table-socketmap
SMAP_VARS=		PLIST_FILES+=${INSTALL_DIR}/table-socketmap \
			PLIST_FILES+=man/man5/table-socketmap.5.gz

SQLITE_CONFIGURE_WITH=	table-sqlite
SQLITE_USES=		sqlite
SQLITE_VARS=		PLIST_FILES+=${INSTALL_DIR}/table-sqlite \
			PLIST_FILES+=man/man5/table-sqlite.5.gz

.include <bsd.port.mk>
