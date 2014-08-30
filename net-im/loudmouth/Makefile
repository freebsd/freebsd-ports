# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	loudmouth
PORTVERSION=	1.4.3
PORTREVISION=	10
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight Jabber client library

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	glib20
CONFIGURE_ARGS=	--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-Bsymbolic -L${LOCALBASE}/lib

OPTIONS_DEFAULT=GNUTLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=openssl
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

.if !${PORT_OPTIONS:MGNUTLS} && !${PORT_OPTIONS:MOPENSSL}
CONFIGURE_ARGS+=--without-ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/loudmouth/lm-ssl-gnutls.c

.include <bsd.port.mk>
