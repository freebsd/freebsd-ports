PORTNAME=	notification

COMMENT=	New mail notification plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugin.php?plugin=notification

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libcanberra-gtk3.so:audio/libcanberra-gtk3 \
		libcanberra.so:audio/libcanberra
USES=		xorg
USE_XORG=	x11

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
