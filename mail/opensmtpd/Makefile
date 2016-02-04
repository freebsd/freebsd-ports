# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	5.7.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
DISTNAME=	${PORTNAME}-${PORTVERSION}p2

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	CA_BUNDLE LIBASRDEVEL MAILERCONF PAM TABLE_DB

OPTIONS_DEFAULT=	CA_BUNDLE PAM TABLE_DB

CA_BUNDLE_DESC=	Install CA bundle for OpenSSL
LIBASRDEVEL_DESC=	Use development version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe libtool
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=	yes
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

CA_BUNDLE_CONFIGURE_ON=	--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

LIBASRDEVEL_LIB_DEPENDS_OFF=	libasr.so:${PORTSDIR}/dns/libasr
LIBASRDEVEL_LIB_DEPENDS=	libasr.so:${PORTSDIR}/dns/libasr-devel

PAM_CONFIGURE_ON=	--with-pam --with-pam-service=smtpd

TABLE_DB_CONFIGURE_ON=	--enable-table-db

.include <bsd.port.mk>
