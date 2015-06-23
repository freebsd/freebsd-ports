# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	201506112227
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}p1

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:${PORTSDIR}/devel/libevent2

OPTIONS_DEFINE=	CA_BUNDLE LIBASR MAILERCONF

OPTIONS_DEFAULT=	CA_BUNDLE PAM

CA_BUNDLE_DESC=	Install CA bundle for OpenSSL
LIBASR_DESC=	Use stable version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libevent-dir=${LOCALBASE} --sysconfdir=${PREFIX}/etc/mail/ \
		--with-mailwrapper --with-ssl-dir=${OPENSSLBASE} --enable-table-db

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd

OPTIONS_SUB=		yes

LIBASR_LIB_DEPENDS_OFF=	libasr.so:${PORTSDIR}/dns/libasr-devel
LIBASR_LIB_DEPENDS=	libasr.so:${PORTSDIR}/dns/libasr

CA_BUNDLE_CONFIGURE_ON=	--with-ca-file=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss

USE_OPENSSL=		yes
WITH_OPENSSL_PORT=	yes

post-deinstall:
		@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
