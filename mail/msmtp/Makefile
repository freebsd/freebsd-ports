# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.4.30
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

LICENSE=	GPLv3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN1=	msmtp.1
INFO=	msmtp

OPTIONS_DEFINE=	GSASL NLS IDN GNOME_KEYRING MSMTPQ
OPTIONS_RADIO=	TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	MSMTPQ OPENSSL

GNUTLS_DESC=	GnuTLS support
OPENSSL_DESC=	SSL (Secure Socket Layer) support
GSASL_DESC=	GSASL support
IDN_DESC=	Internationalized Domain Names support
GNOME_KEYRING_DESC=	GNOME Keyring auth support
MSMTPQ_DESC=	Install offline messaging scripts

.include       <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		libssl_CFLAGS="-I${OPENSSLINC}" libssl_LIBS="-L${OPENSSLLIB} -lssl"
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.if ${PORT_OPTIONS:MGNUTLS} || ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if ${PORT_OPTIONS:MGSASL}
LIB_DEPENDS+=	gsasl:${PORTSDIR}/security/gsasl
CONFIGURE_ARGS+=	--with-libgsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if ${PORT_OPTIONS:MGNOME_KEYRING}
CONFIGURE_ARGS+=	--with-gnome-keyring
LIB_DEPENDS+=	gnome-keyring:${PORTSDIR}/security/gnome-keyring
.else
CONFIGURE_ARGS+=	--without-gnome-keyring
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MMSMTPQ}
PLIST_SUB+=	MSMTPQ=""

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtp-queue ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtpq ${PREFIX}/bin
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/msmtpq/README.msmtpq ${DOCSDIR}
.else
PLIST_SUB+=	MSMTPQ="@comment "
.endif

.include <bsd.port.post.mk>
