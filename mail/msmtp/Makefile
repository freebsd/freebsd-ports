# Created by: R.I.Pienaar <rip@devco.net>
# $FreeBSD$

PORTNAME=	msmtp
PORTVERSION=	1.4.32
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

LICENSE=	GPLv3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INFO=	msmtp

OPTIONS_DEFINE=	GSASL NLS IDN GNOMEKEYRING MSMTPQ
OPTIONS_RADIO=	TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	MSMTPQ OPENSSL

GSASL_DESC=	GSASL support
MSMTPQ_DESC=	Install offline messaging scripts

.include       <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		libssl_CFLAGS="-I${OPENSSLINC}" \
			libssl_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.if ${PORT_OPTIONS:MGNUTLS} || ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if ${PORT_OPTIONS:MGSASL}
LIB_DEPENDS+=	libgsasl.so:${PORTSDIR}/security/gsasl
CONFIGURE_ARGS+=	--with-libgsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if ${PORT_OPTIONS:MGNOMEKEYRING}
CONFIGURE_ARGS+=	--with-gnome-keyring
LIB_DEPENDS+=	libgnome-keyring.so:${PORTSDIR}/security/gnome-keyring
.else
CONFIGURE_ARGS+=	--without-gnome-keyring
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
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
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtp-queue ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/msmtpq/msmtpq ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/msmtpq/README.msmtpq ${STAGEDIR}${DOCSDIR}
.else
PLIST_SUB+=	MSMTPQ="@comment "
.endif

.include <bsd.port.post.mk>
