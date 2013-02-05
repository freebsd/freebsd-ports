# New ports collection makefile for:    mpop
# Date created:         2009-10-24
# Whom:                 Sylvio Cesar <sylvio@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpop
PORTVERSION=	1.0.27
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MPOP is a small and fast POP3 client

LIB_DEPENDS=	idn.17:${PORTSDIR}/dns/libidn

OPTIONS_DEFINE=	GNUTLS GSASL
GNUTLS_DESC=	GNUTLS Enable gnuTLS support
GSASL_DESC=	GSASL GNU SASL authentication support

OPTIONS_DEFINE=	NLS

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libidn

MAN1=	mpop.1
INFO=	mpop

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		gnutls.26:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-ssl=openssl
.endif

.if ${PORT_OPTIONS:MGSASL}
LIB_DEPENDS+=		gsasl.16:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl-prefix
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.mk>
