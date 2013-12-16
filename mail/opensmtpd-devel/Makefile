# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	201312142054
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	OpenSMTPD is a free MTA (development snapshot)

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	event-1:${PORTSDIR}/devel/libevent

OPENSMTPD_SNAPSHOT_VER=	p1

OPTIONS_DEFINE=	CA_BUNDLE PAM SQLITE MYSQL PGSQL LDAP

OPTIONS_DEFAULT=	CA_BUNDLE PAM

CA_BUNDLE_DESC=	Install CA bundle for OpenSSL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE} --sysconfdir=${PREFIX}/etc/mail/ \
		--with-mailwrapper

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-[0-9]*

MAN8=		makemap.8 newaliases.8 sendmail.8 smtpctl.8 smtpd.8
MAN5=		smtpd.conf.5 aliases.5 forward.5

USERS=		_smtpd _smtpq
GROUPS=		_smtpd

OPTIONS_SUB=		MYSQL SQLITE PGSQL LDAP

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

PAM_CONFIGURE_ON=	--with-pam

.include <bsd.port.options.mk>

USE_OPENSSL=	yes

# FreeBSD 7.3 and earlier need to use OpenSSL from ports
.if ${OSVERSION} < 704000
WITH_OPENSSL_PORT=	yes
.endif

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
