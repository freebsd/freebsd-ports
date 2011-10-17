# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.4.25
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

LICENSE=	GPLv3

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN1=	msmtp.1
INFO=	msmtp

OPTIONS=	GNUTLS "Adds GnuTLS support" off \
		OPENSSL "Adds support for SSL (Secure Socket Layer)" on \
		GSASL "Adds GSASL support" off \
		NLS "Native Language Support via gettext utilities" on \
		IDN "Enable Internationalized Domain Names" on \
		GNOME_KEYRING "Build with GNOME Keyring auth support" off

.include       <bsd.port.options.mk>

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.47:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
CONFIGURE_ENV+=		libssl_CFLAGS="-I${OPENSSLINC}" libssl_LIBS="-L${OPENSSLLIB} -lssl"
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(WITH_GNUTLS) || defined(WITH_OPENSSL)
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=	gsasl.15:${PORTSDIR}/security/gsasl
CONFIGURE_ARGS+=	--with-libgsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

.if !defined(WITHOUT_IDN)
LIB_DEPENDS+=	idn.17:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
.endif

.if !defined(WITH_GNOME_KEYRING)
CONFIGURE_ARGS+=	--without-gnome-keyring
.else
CONFIGURE_ARGS+=	--with-gnome-keyring
LIB_DEPENDS+=	gnome-keyring.0:${PORTSDIR}/security/gnome-keyring
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.mk>
