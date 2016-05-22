# Created by: gahr
# $FreeBSD$

PORTNAME=	opensmtpd-extras
PORTVERSION=	201605182041
PORTREVISION?=	0
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

# NB: Please *DO NOT* add the following; they are NOT for end-users:
# filter-monkey, filter-stub, filter-trace, filter-void
# queue-null, queue-stub
# scheduler-stub
# table-stub
.if empty(SLAVE_PORT)
OPTIONS_GROUP=		FILTER TABLE
OPTIONS_GROUP_FILTER=	CLAMAV DKIM DNSBL PAUSE REGEX SPAMASSASSIN
OPTIONS_GROUP_TABLE=	LDAP MYSQL PASSWD PGSQL PYTHON REDIS SMAP SQLITE
OPTIONS_DEFAULT=	${OPTIONS_GROUP_FILTER} ${OPTIONS_GROUP_TABLE}

# Filters
CLAMAV_DESC=		Check messages with ClamAV
DKIM_DESC=		Sign messages with DKIM
DNSBL_DESC=		Check messages against DNSBLs
PAUSE_DESC=		Pause incoming messages to reduce spam
SPAMASSASSIN_DESC=	Check messages with SpamAssassin
# Tables
PASSWD_DESC=		passwd(5) table support
SMAP_DESC=		Socketmap protocol support

PLIST_FILES=	man/man3/filter_api.3.gz
INSTALL_DIR=	${LOCALBASE}/libexec/opensmtpd

NO_ARCH=	yes

#
# Filters
#
CLAMAV_RUN_DEPENDS=		${INSTALL_DIR}/filter-clamav:mail/opensmtpd-extras-filter-clamav
DKIM_RUN_DEPENDS=		${INSTALL_DIR}/filter-dkim-signer:mail/opensmtpd-extras-filter-dkim
DNSBL_RUN_DEPENDS=		${INSTALL_DIR}/filter-dnsbl:mail/opensmtpd-extras-filter-dnsbl
PAUSE_RUN_DEPENDS=		${INSTALL_DIR}/filter-pause:mail/opensmtpd-extras-filter-pause
REGEX_RUN_DEPENDS=		${INSTALL_DIR}/filter-regex:mail/opensmtpd-extras-filter-regex
SPAMASSASSIN_RUN_DEPENDS=	${INSTALL_DIR}/filter-spamassassin:mail/opensmtpd-extras-filter-spamassassin

#
# Tables
#
MYSQL_RUN_DEPENDS=	${INSTALL_DIR}/table-mysql:mail/opensmtpd-extras-table-mysql
PASSWD_RUN_DEPENDS=	${INSTALL_DIR}/table-passwd:mail/opensmtpd-extras-table-passwd
PGSQL_RUN_DEPENDS=	${INSTALL_DIR}/table-postgres:mail/opensmtpd-extras-table-postgresql
PYTHON_RUN_DEPENDS=	${INSTALL_DIR}/table-python:mail/opensmtpd-extras-table-python
REDIS_RUN_DEPENDS=	${INSTALL_DIR}/table-redis:mail/opensmtpd-extras-table-redis
SMAP_RUN_DEPENDS=	${INSTALL_DIR}/table-socketmap:mail/opensmtpd-extras-table-socketmap
SQLITE_RUN_DEPENDS=	${INSTALL_DIR}/table-sqlite:mail/opensmtpd-extras-table-sqlite
.else

# Only install this for the opensmtpd-extras master port
pre-patch:
	@${REINPLACE_CMD} -e '/man_MANS.*filter_api.3/s/^/#/' \
		${WRKSRC}/extras/wip/filters/Makefile.am

.endif

.include <bsd.port.mk>
