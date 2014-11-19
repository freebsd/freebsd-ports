# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/sysutils/system-tools-backends/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	system-tools-backends
PORTVERSION=	2.10.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Backend system admin scripts for gnome-system-tools

BUILD_DEPENDS=	p5-Net-DBus>=0:${PORTSDIR}/devel/p5-Net-DBus
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	p5-Net-DBus>=0:${PORTSDIR}/devel/p5-Net-DBus

USES=		gmake pathfix perl5 pkgconfig tar:bzip2
USE_GNOME=	intlhack glib20
GNU_CONFIGURE=	yes
USE_GNOME_SUBR=	yes
CONFIGURE_ARGS=	--with-stb-group=wheel \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@${REINPLACE_CMD} -e 's|@GETTEXT_PACKAGE@|system-tools-backends|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
