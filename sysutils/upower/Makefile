# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/upower/Makefile 18681 2013-09-15 22:52:32Z marcus $

PORTNAME=	upower
PORTVERSION=	0.9.21
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

NO_STAGE=	yes
USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	intlhack ltverhack glib20 introspection:build
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	GTKDOC="false"

.if defined(NO_INSTALL_MANPAGES)
CONFIGURE_ARGS+=--disable-man-pages
.else
BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410 \
    		${LOCALBASE}/share/xml/docbook/4.1.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-sk \
    		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=		upower.1
MAN7=		UPower.7
MAN8=		upowerd.8
.endif

.include <bsd.port.mk>
