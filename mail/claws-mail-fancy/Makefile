# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	fancy
PORTREVISION=	0

COMMENT=	Webkit based HTML renderer plugin for Claws Mail

LIB_DEPENDS=	libsoup-gnome-2.4.so:devel/libsoup-gnome \
		libwebkitgtk-1.0.so:www/webkit-gtk2

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

CLAWS_PLUGINS_BUILD=	fancy

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
