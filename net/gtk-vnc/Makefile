# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtk-vnc
PORTVERSION=	0.3.10
PORTREVISION=	8
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	VNC viewer widget for GTK+

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

CONFLICTS=	gtk-vnc-0.4.[0-9]*

NO_STAGE=	yes
USE_GNOME=	pygtk2
USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-gtkglext=yes

.include <bsd.port.mk>
