# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/branches/GNOME_3_12/net/gtk-vnc/Makefile 19919 2014-09-26 09:26:39Z kwm $

PORTNAME=	gtk-vnc
PORTVERSION=	0.4.4
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	vapigen:${PORTSDIR}/lang/vala-vapigen
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2

USE_GNOME=	gnomehier gtk30 introspection:build
USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtk=3.0 --enable-introspection \
		--disable-plugin --without-python
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
