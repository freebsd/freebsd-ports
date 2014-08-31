# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	5.4.2
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	OpenSMTPD is a free MTA

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	CA_BUNDLE PAM SQLITE MYSQL PGSQL LDAP REDIS

OPTIONS_DEFAULT=	CA_BUNDLE PAM

CA_BUNDLE_DESC=	Install CA bundle for OpenSSL

USES=		libtool
USE_AUTOTOOLS=	autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE} --sysconfdir=${PREFIX}/etc/mail/ \
		--with-mailwrapper

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-devel-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd

OPTIONS_SUB=		MYSQL SQLITE PGSQL LDAP REDIS

CA_BUNDLE_CONFIGURE_ON=	--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

MYSQL_USE=		MYSQL=yes
MYSQL_CFLAGS=		-I${LOCALBASE}/include/mysql
MYSQL_LDFLAGS=		-L${LOCALBASE}/lib/mysql
MYSQL_CONFIGURE_ON=	--with-experimental-mysql

SQLITE_USE=		SQLITE=3
SQLITE_CFLAGS=		-I${LOCALBASE}/include
SQLITE_LDFLAGS=		-L${LOCALBASE}/lib
SQLITE_CONFIGURE_ON=	--with-experimental-sqlite

PGSQL_USE=		PGSQL=yes
PGSQL_CONFIGURE_ON=	--with-experimental-postgres

LDAP_CONFIGURE_ON=	--with-experimental-ldap

PAM_CONFIGURE_ON=	--with-pam --with-pam-service=smtpd

REDIS_LIB_DEPENDS=	libhiredis.so:${PORTSDIR}/databases/hiredis
REDIS_CONFIGURE_ON=	--with-experimental-redis

.include <bsd.port.options.mk>

USE_OPENSSL=	yes

# FreeBSD 7.3 and earlier need to use OpenSSL from ports
.if ${OSVERSION} < 704000
WITH_OPENSSL_PORT=	yes
.endif

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
