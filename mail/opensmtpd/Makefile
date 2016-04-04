# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	5.7.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}p2

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent2

OPTIONS_DEFINE=	CA_BUNDLE LIBASRDEVEL MAILERCONF PAM SSL_PORT TABLE_DB

OPTIONS_DEFAULT=	CA_BUNDLE PAM TABLE_DB

CA_BUNDLE_DESC=	Install CA bundle for SSL
LIBASRDEVEL_DESC=	Use development version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
SSL_PORT_DESC=		SSL/TLS support via OpenSSL/LibreSSL from port
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE} --sysconfdir=${PREFIX}/etc/mail/ \
		--with-mailwrapper --with-ssl-dir=${OPENSSLBASE}

CPE_VENDOR=	openbsd

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-devel-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd

OPTIONS_SUB=	yes

CA_BUNDLE_CONFIGURE_WITH=	ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

LIBASRDEVEL_LIB_DEPENDS_OFF=	libasr.so:dns/libasr
LIBASRDEVEL_LIB_DEPENDS=	libasr.so:dns/libasr-devel
LIBASRDEVEL_BROKEN=		incompatible with libasr-devel

PAM_CONFIGURE_WITH=	pam pam-service=smtpd

TABLE_DB_CONFIGURE_ENABLE=	table-db

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000 && ! ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.mk>
