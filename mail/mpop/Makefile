# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpop
DISTVERSION=	1.2.2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast POP3 client

LICENSE=	GPLv3 # (or later)

USES=		gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules

INFO=		mpop

OPTIONS_DEFINE=		GSASL IDN LIBSECRET NLS
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	IDN OPENSSL
OPTIONS_SUB=		yes

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_ON=	--with-tls=gnutls
GSASL_DESC=		SASL authentication support via GNU SASL
GSASL_LIB_DEPENDS=	libgsasl.so:${PORTSDIR}/security/gsasl
GSASL_CONFIGURE_OFF=	--without-libgsasl
IDN_LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn
IDN_CONFIGURE_WITH=	libidn
LIBSECRET_DESC=		GNOME password management
LIBSECRET_LIB_DEPENDS=	libsecret-1.so:${PORTSDIR}/security/libsecret
LIBSECRET_CONFIGURE_WITH=	libsecret
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_USE=		openssl=yes
OPENSSL_CONFIGURE_ON=	--with-tls=openssl \
			libssl_CFLAGS=-I${OPENSSLINC} \
			libssl_LIBS="-lssl -lcrypto"

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MGNUTLS) && empty(PORT_OPTIONS:MOPENSSL)
CONFIGURE_ARGS+=	--with-tls=no
.endif

.include <bsd.port.mk>
