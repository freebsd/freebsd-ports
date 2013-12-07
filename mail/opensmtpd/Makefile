# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	5.4.1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	OpenSMTPD is a free MTA

LICENSE=	ISCL

LIB_DEPENDS=	event-1:${PORTSDIR}/devel/libevent

OPTIONS_DEFINE=	PAM SQLITE MYSQL PGSQL LDAP

OPTIONS_DEFAULT=	PAM

USE_AUTOTOOLS=	autoconf:env automake:env libtool:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE} --sysconfdir=${PREFIX}/etc/mail/ \
		--with-mailwrapper

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-devel-[0-9]*

USERS=		_smtpd _smtpq _smtpf
GROUPS=		_smtpd

.include <bsd.port.options.mk>

USE_OPENSSL=	yes

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=	--with-experimental-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=		3
CONFIGURE_ARGS+=	--with-experimental-sqlite
PLIST_SUB+=	SQLITE=""
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-experimental-postgres
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-experimental-ldap
PLIST_SUB+=	LDAP=""
.else
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
.endif

# FreeBSD 7.3 and earlier need to use OpenSSL from ports
.if ${OSVERSION} < 704000
WITH_OPENSSL_PORT=	yes
.endif

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
