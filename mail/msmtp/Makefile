# Created by: R.I.Pienaar <rip@devco.net>
# $FreeBSD$

PORTNAME=	msmtp
PORTVERSION=	1.8.15
CATEGORIES=	mail
MASTER_SITES=	https://marlam.de/msmtp/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		gmake makeinfo pkgconfig tar:xz
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO=	msmtp

OPTIONS_DEFINE=	DOCS GSASL NLS IDN LIBSECRET MSMTPD MSMTPQ
OPTIONS_RADIO=	TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	GNUTLS MSMTPD MSMTPQ
OPTIONS_SUB=	yes

GSASL_DESC=	GSASL support
LIBSECRET_DESC=	GNOME password management
MSMTPD_DESC=	Include minimal SMTP server that pipes mails to msmtp
MSMTPQ_DESC=	Install offline messaging scripts

GSASL_CONFIGURE_WITH=	libgsasl
GSASL_LIB_DEPENDS=	libgsasl.so:security/libgsasl
IDN_CONFIGURE_WITH=	libidn
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
LIBSECRET_CONFIGURE_WITH=	libsecret
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:security/libsecret
MSMTPD_CONFIGURE_WITH=	msmtpd
MSMTPQ_PORTDOCS=	README.msmtpq
MSMTPQ_RUN_DEPENDS=	bash:shells/bash
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

GNUTLS_CONFIGURE_ON=	--with-tls=gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-tls=openssl
OPENSSL_CONFIGURE_ENV=	libssl_CFLAGS="-I${OPENSSLINC}" \
			libssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
CERTSFILE=		${LOCALBASE}/share/certs/ca-root-nss.crt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS} || ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${CERTSFILE}:security/ca_root_nss
.else
CONFIGURE_ARGS+=	--with-tls=no
.endif

post-extract:
	@${REINPLACE_CMD} -e 's|/etc/ssl/certs/ca\\-certificates.crt|${CERTSFILE}|' \
		${WRKSRC}/doc/msmtp.1

.if ${PORT_OPTIONS:MMSMTPQ}
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtp-queue ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtpq ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/README.msmtpq ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
