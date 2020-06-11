# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	notification
PORTREVISION=	0

COMMENT=	New mail notification plugin for Claws Mail

LIB_DEPENDS=	libcanberra-gtk.so:audio/libcanberra \
		libnotify.so:devel/libnotify

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
