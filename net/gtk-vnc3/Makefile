# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-vnc
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

CONFLICTS=	gtk-vnc-0.3.[0-9]*

USE_XZ=		yes
USE_GNOME=	gtk30
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 --disable-introspection \
		--disable-plugin --without-python

.include <bsd.port.mk>
