# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	notification
PORTREVISION=	1

COMMENT=	New mail notification plugin for Claws Mail

LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libnotify.so:${PORTSDIR}/devel/libnotify

CLAWS_PLUGINS_BUILD=	notification

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
