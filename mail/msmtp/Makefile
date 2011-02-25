# Ports collection makefile for:  msmtp
# Date created:                   22 Aug 2003
# Whom:                           R.I.Pienaar <rip@devco.net>
#
# $FreeBSD$
#

PORTNAME=	msmtp
PORTVERSION=	1.4.23
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	SF

MAINTAINER=	novel@FreeBSD.org
COMMENT=	SMTP plugin for MUAs

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=	msmtp.1
INFO=	msmtp

LICENSE=	GPLv3

OPTIONS=	GNUTLS "Adds GnuTLS support" off \
		OPENSSL "Adds support for SSL (Secure Socket Layer)" off \
		GSASL "Adds GSASL support" off \
		NLS "Native Language Support via gettext utilities" on \
		IDN "Enable Internationalized Domain Names" on \

.include       <bsd.port.options.mk>

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif defined(WITH_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=openssl
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
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-libidn
.else
CONFIGURE_ARGS+=	--without-libidn
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
