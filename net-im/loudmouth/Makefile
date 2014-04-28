# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/loudmouth/Makefile 19593 2014-04-28 11:41:58Z gusi $

PORTNAME=	loudmouth
PORTVERSION=	1.4.3
PORTREVISION=	7
CATEGORIES=	net-im gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight Jabber client library

LIB_DEPENDS=	libidn.so:${PORTSDIR}/dns/libidn

USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	glib20
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
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

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*

.include <bsd.port.mk>
