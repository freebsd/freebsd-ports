# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.2.0
CATEGORIES=	mail xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mail notification applet for the Xfce panel

LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
INSTALLS_ICONS=	yes
USES=		gettext gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	configenv libexo libmenu libutil panel
USE_XORG=	x11

CONFIGURE_ARGS=--enable-ipv6

.include <bsd.port.mk>
