# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/sysutils/gnome-power-manager/Makefile,v 1.73 2011/04/30 20:43:26 mezz Exp $

PORTNAME=	gnome-power-manager
PORTVERSION=	2.32.0
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the GNOME Desktop

LIB_DEPENDS=	libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit

CONFLICTS=	gnome-power-manager-3.[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix intlhack libwnck gnomedocutils gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--enable-hal
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

GCONF_SCHEMAS=	gnome-power-manager.schemas

BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1:${PORTSDIR}/textproc/docbook-sgml

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv|| ; s|-Werror||g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
