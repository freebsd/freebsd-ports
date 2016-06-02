# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	201605221711
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

OPTIONS_DEFINE=		CA_BUNDLE LIBASR MAILERCONF PAM SSL_PORT TABLE_DB

OPTIONS_DEFAULT=	CA_BUNDLE PAM TABLE_DB

CA_BUNDLE_DESC=		Install CA bundle for SSL
LIBASR_DESC=		Use stable version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
SSL_PORT_DESC=		SSL/TLS support via OpenSSL/LibreSSL from port
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe libtool
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

CPE_VENDOR=	openbsd

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd _smtpq

OPTIONS_SUB=	yes

CA_BUNDLE_CONFIGURE_WITH=	path-CAfile=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

LIBASR_LIB_DEPENDS=	libasr.so:dns/libasr
LIBASR_LIB_DEPENDS_OFF=	libasr.so:dns/libasr-devel

PAM_CONFIGURE_WITH=	auth-pam=smtpd
SSL_PORT_VARS=		with_openssl_port=yes
TABLE_DB_CONFIGURE_WITH=	table-db

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 1000015
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-libasr=${LOCALBASE} \
			--with-libevent=${LOCALBASE} \
			--with-libssl=${OPENSSLBASE} \
			--sysconfdir=${PREFIX}/etc/mail/

post-patch:
	${REINPLACE_CMD} -e '/chmod 2555/d' ${WRKSRC}/mk/smtpctl/Makefile.in
	# https://github.com/OpenSMTPD/OpenSMTPD/issues/700
	${REINPLACE_CMD} -r -e \
		'/SMTPD_VERSION/s/"[^"]+"$$/"${PORTVERSION}${DISTVERSIONSUFFIX}"/' \
		${WRKSRC}/smtpd/smtpd.h

.if ${PORT_OPTIONS:MTABLE_DB}
post-install:
	@${LN} -sf ${PREFIX}/sbin/smtpctl ${STAGEDIR}${PREFIX}/libexec/opensmtpd/makemap
.endif

.include <bsd.port.post.mk>
