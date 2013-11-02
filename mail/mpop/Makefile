# Created by: Sylvio Cesar <sylvio@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mpop
PORTVERSION=	1.0.28
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	MPOP is a small and fast POP3 client

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

OPTIONS_DEFINE=	GSASL NLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_SUB=	yes

GSASL_DESC=	GSASL GNU SASL authentication support

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-libidn

INFO=	mpop

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-ssl=gnutls
.elif ${PORT_OPTIONS:MOPENSSL}
USE_GCC=		yes
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-ssl=openssl \
			libssl_CFLAGS=-I${OPENSSLINC} \
			libssl_LIBS=-lssl
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.if ${PORT_OPTIONS:MGSASL}
LIB_DEPENDS+=		libgsasl.so:${PORTSDIR}/security/gsasl
.else
CONFIGURE_ARGS+=	--without-libgsasl
.endif

.include <bsd.port.mk>
