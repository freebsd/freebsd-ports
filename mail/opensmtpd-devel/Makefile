# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	201602131907
DISTVERSIONSUFFIX=	p1
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/ \
		http://distfiles.pirateparty.in/ashish/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent2

OPTIONS_DEFINE=	CA_BUNDLE LIBASR MAILERCONF PAM SSL_PORT

OPTIONS_DEFAULT=	CA_BUNDLE PAM

CA_BUNDLE_DESC=		Install CA bundle for SSL
LIBASR_DESC=		Use stable version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
SSL_PORT_DESC=		SSL/TLS support via OpenSSL/LibreSSL from port

USES=		cpe libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-table-db \
		--sysconfdir=${PREFIX}/etc/mail/ \
		--with-libasr=${LOCALBASE} \
		--with-libevent=${LOCALBASE} \
		--with-libssl=${OPENSSLBASE} \
		--with-group-queue=${GROUPS}

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall

CPE_VENDOR=	openbsd

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd

PLIST_SUB+=	SMTPQ_GROUP=${GROUPS}

OPTIONS_SUB=		yes

LIBASR_LIB_DEPENDS_OFF=	libasr.so:dns/libasr-devel
LIBASR_LIB_DEPENDS=	libasr.so:dns/libasr

CA_BUNDLE_CONFIGURE_WITH=	path-CAfile=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

PAM_CONFIGURE_WITH=	auth-pam=smtpd

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000 && ! ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=	yes
.endif

post-install:
	@${LN} -sf ${PREFIX}/sbin/smtpctl ${STAGEDIR}${PREFIX}/libexec/opensmtpd/makemap

.include <bsd.port.mk>
