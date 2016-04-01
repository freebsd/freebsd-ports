# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	virt-viewer
PORTVERSION=	3.1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://virt-manager.org/download/sources/${PORTNAME}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Provides a graphical viewer for a guest OS display

LICENSE=	GPLv2

BUILD_DEPENDS=	xml2-config:textproc/libxml2 \
		intltoolize:textproc/intltool \
		spice-protocol>=0.12.7:devel/spice-protocol
LIB_DEPENDS=	libvirt.so:devel/libvirt \
		libgtk-vnc-2.0.so:net/gtk-vnc \
		libspice-client-glib-2.0.so:deskutils/spice-gtk

USE_OPENSSL=yes
WITH_OPENSSL_PORT=yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share
CONFIGURE_ARGS=	--with-gtk=3.0 --with-spice-gtk
USES=		desktop-file-utils gmake pkgconfig shared-mime-info cpe
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes
CPE_VENDOR=	redhat

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
