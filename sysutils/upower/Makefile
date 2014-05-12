# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/upower/Makefile,v 1.19 2010/10/05 08:30:15 kwm Exp $

PORTNAME=	upower
PORTVERSION=	0.9.7
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://upower.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	D-Bus daemon for simplifying power management tasks

LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING
USES=		gettext gmake libtool:keepla pathfix pkgconfig tar:bzip2
USE_GNOME=	intlhack glib20 introspection:build,run
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-backend=freebsd \
		--localstatedir=/var
CONFIGURE_ENV=	GTKDOC="false"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

BUILD_DEPENDS+=	${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml \
		${LOCALBASE}/share/xml/docbook/4.1.2:${PORTSDIR}/textproc/docbook-xml \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

post-install:
	@${MKDIR} ${STAGEDIR}/var/lib/DeviceKit-power

.include <bsd.port.mk>
