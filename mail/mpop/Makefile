# New ports collection makefile for:    mpop
# Date created:         2009-10-24
# Whom:                 Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpop
PORTVERSION=	1.0.23
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MPOP is a small and fast POP3 client

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn

OPTIONS=	GNUTLS  "Enable gnuTLS support" on \
		GSASL "GNU SASL authentication support" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libidn

MAN1=	mpop.1
INFO=	mpop

.include <bsd.port.options.mk>

.if defined(WITH_GNUTLS)
LIB_DEPENDS+=		gnutls.40:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

.if defined(WITH_GSASL)
LIB_DEPENDS+=		gsasl.15:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl-prefix
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
