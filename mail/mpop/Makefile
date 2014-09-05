# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpop
PORTVERSION=	1.0.29
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast POP3 client

LICENSE=	GPLv3 # (or later)

USES=		pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

INFO=		mpop

OPTIONS_DEFINE=		GNOMEKEYRING GSASL IDN NLS
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	IDN OPENSSL
OPTIONS_SUB=		yes

GNOMEKEYRING_LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/libgnome-keyring
GNOMEKEYRING_CONFIGURE_WITH=	gnome-keyring
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ON=	--with-ssl=gnutls
GSASL_DESC=		SASL authentication support via GNU SASL
GSASL_LIB_DEPENDS=	libgsasl.so:${PORTSDIR}/security/gsasl
GSASL_CONFIGURE_OFF=	--without-libgsasl
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IDN_CONFIGURE_WITH=	libidn
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_USE=		openssl=yes
OPENSSL_CONFIGURE_ON=	--with-ssl=openssl \
			libssl_CFLAGS=-I${OPENSSLINC} \
			libssl_LIBS="-lssl -lcrypto"

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MGNUTLS) && empty(PORT_OPTIONS:MOPENSSL)
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.include <bsd.port.mk>
