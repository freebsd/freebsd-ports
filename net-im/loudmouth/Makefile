# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/loudmouth/Makefile 19914 2014-09-25 22:33:21Z kwm $

PORTNAME=	loudmouth
PORTVERSION=	1.5.3
CATEGORIES=	net-im
MASTER_SITES=	https://mcabber.com/files/loudmouth/ \
		http://www.lilotux.net/~mikael/mcabber/files/loudmouth/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Lightweight Jabber client library

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libidn.so:dns/libidn

USES=		gettext gmake libtool pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --disable-rebuilds \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=GNUTLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
CONFIGURE_ARGS+=--with-ssl=gnutls
.elif ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=openssl
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
.else
CONFIGURE_ARGS+=--without-ssl
.endif

.include <bsd.port.mk>
