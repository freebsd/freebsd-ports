# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net/gtk-vnc/Makefile 19814 2014-08-15 20:17:00Z gusi $

PORTNAME=	gtk-vnc
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USE_GNOME=	gnomehier gtk30 introspection:build
USES=		gettext gmake pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 --enable-introspection \
		--disable-plugin --without-python
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
