# Created by: gahr
# $FreeBSD$

PORTNAME=	opensmtpd-extras
PORTVERSION=	201602042118
PORTREVISION?=	2
CATEGORIES+=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER?=	gahr@FreeBSD.org
COMMENT?=	Addons for OpenSMTPD

LICENSE?=	ISCL

LIB_DEPENDS+=	libevent.so:devel/libevent2
RUN_DEPENDS+=	${LOCALBASE}/sbin/smtpctl:mail/opensmtpd

USES+=		autoreconf libtool pkgconfig
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
GNU_CONFIGURE=	yes

.if empty(SLAVE_PORT)
OPTIONS_GROUP=		FILTER TABLE
OPTIONS_GROUP_FILTER=	SPAMASSASSIN
OPTIONS_GROUP_TABLE=	LDAP MYSQL PASSWD PGSQL PYTHON REDIS SMAP SQLITE
OPTIONS_DEFAULT=	${OPTIONS_GROUP_FILTER} ${OPTIONS_GROUP_TABLE}

# Filters
SPAMASSASSIN_DESC=	Check messages with SpamAssassin
# Tables
PASSWD_DESC=	passwd(5) table support
SMAP_DESC=	Socketmap protocol support

OPTIONS_SUB=	yes

PLIST_FILES=	man/man3/filter_api.3.gz
INSTALL_DIR=	${LOCALBASE}/libexec/opensmtpd

NO_ARCH=	yes

#
# Filters
#

SPAMASSASSIN_BUILD_DEPENDS=	${INSTALL_DIR}/filter-spamassassin:mail/opensmtpd-extras-filter-spamassassin
SPAMASSASSIN_RUN_DEPENDS=	${SPAMASSASSIN_BUILD_DEPENDS}

#
# Tables
#

MYSQL_BUILD_DEPENDS=	${INSTALL_DIR}/table-mysql:mail/opensmtpd-extras-table-mysql
MYSQL_RUN_DEPENDS=	${MYSQL_BUILD_DEPENDS}

PASSWD_BUILD_DEPENDS=	${INSTALL_DIR}/table-passwd:mail/opensmtpd-extras-table-passwd
PASSWD_RUN_DEPENDS=	${PASSWD_BUILD_DEPENDS}

PGSQL_BUILD_DEPENDS=	${INSTALL_DIR}/table-postgres:mail/opensmtpd-extras-table-postgresql
PGSQL_RUN_DEPENDS=	${PGSQL_BUILD_DEPENDS}

PYTHON_BUILD_DEPENDS=	${INSTALL_DIR}/table-python:mail/opensmtpd-extras-table-python
PYTHON_RUN_DEPENDS=	${PYTHON_BUILD_DEPENDS}

REDIS_BUILD_DEPENDS=	${INSTALL_DIR}/table-redis:mail/opensmtpd-extras-table-redis
REDIS_RUN_DEPENDS=	${REDIS_BUILD_DEPENDS}

SMAP_BUILD_DEPENDS=	${INSTALL_DIR}/table-socketmap:mail/opensmtpd-extras-table-socketmap
SMAP_RUN_DEPENDS=	${SMAP_BUILD_DEPENDS}

SQLITE_BUILD_DEPENDS=	${INSTALL_DIR}/table-sqlite:mail/opensmtpd-extras-table-sqlite
SQLITE_RUN_DEPENDS=	${SQLITE_BUILD_DEPENDS}
.else

# Only install this for the opensmtpd-extras master port
post-install:
	@${RM} ${STAGEDIR}${MAN3PREFIX}/man/man3/filter_api.3

.endif

.include <bsd.port.mk>
