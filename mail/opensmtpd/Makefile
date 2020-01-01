# Created by: Ashish SHUKLA <ashish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opensmtpd
PORTVERSION=	6.6.1
DISTVERSIONSUFFIX=	p1
PORTEPOCH=	1
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.opensmtpd.org/archives/

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Security- and simplicity-focused SMTP server from OpenBSD

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

OPTIONS_DEFINE=	CA_BUNDLE LIBASRDEVEL MAILERCONF PAM TABLE_DB

OPTIONS_DEFAULT=	CA_BUNDLE PAM TABLE_DB

CA_BUNDLE_DESC=		Use NSS CA bundle for SSL instead of /etc/ssl/cert.pem
LIBASRDEVEL_DESC=	Use development version of libasr
MAILERCONF_DESC=	Activate OpenSMTPD in mailer.conf(5)
TABLE_DB_DESC=		Build table-db plugin (aliases)

USES=		cpe groff libtool ssl
GNU_CONFIGURE=	yes

CPE_VENDOR=	openbsd

USE_RC_SUBR=	smtpd
SUB_FILES=	pkg-install pkg-deinstall pkg-message

CONFLICTS_INSTALL=	postfix-[0-9]* sendmail-[0-9]* opensmtpd-devel-[0-9]*

USERS=		_smtpd _smtpq
GROUPS=		_smtpd _smtpq

OPTIONS_SUB=	yes

CA_BUNDLE_CONFIGURE_WITH=	path-CAfile=${LOCALBASE}/share/certs/ca-root-nss.crt
CA_BUNDLE_RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

LIBASRDEVEL_LIB_DEPENDS_OFF=	libasr.so:dns/libasr
LIBASRDEVEL_LIB_DEPENDS=	libasr.so:dns/libasr-devel

PAM_CONFIGURE_WITH=	auth-pam=smtpd
TABLE_DB_CONFIGURE_WITH=	table-db

CONFIGURE_ARGS+=	--with-libasr=${LOCALBASE} \
			--with-libevent=${LOCALBASE} \
			--sysconfdir=${PREFIX}/etc/mail/

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && \
    (${OSVERSION} < 1200084 && ${SSL_DEFAULT} == "base")
BROKEN=		Openssl 1.0 API is EoL, upgrade to FreeBSD 12.x/13.x or add DEFAULT_VERSIONS+=ssl=[openssl|libressl*] to /etc/make.conf
.endif

post-install-TABLE_DB-on:
	@${LN} -sf ${PREFIX}/sbin/smtpctl ${STAGEDIR}${PREFIX}/libexec/opensmtpd/makemap

.include <bsd.port.post.mk>
