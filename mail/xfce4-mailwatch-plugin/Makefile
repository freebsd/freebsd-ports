# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-mailwatch-plugin
PORTVERSION=	1.2.0
PORTREVISION=	8
CATEGORIES=	mail xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Mail notification applet for the Xfce panel

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XFCE=	panel
USE_XORG=	x11

CONFIGURE_ARGS=--enable-ipv6

post-patch:
	${REINPLACE_CMD} -e 's|xfce-mail|mail-send|' \
		${WRKSRC}/panel-plugin/mailwatch-plugin.c

.include <bsd.port.mk>
