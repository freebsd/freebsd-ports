PORTNAME=	notification

COMMENT=	New mail notification plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugin.php?plugin=notification

LIB_DEPENDS=	libnotify.so:devel/libnotify

.include "../claws-mail/Makefile.ver"

.if ${MASTER_OPTIONS:MGTK2}
LIB_DEPENDS+=	libcanberra-gtk.so:audio/libcanberra-gtk2
.endif
.if ${MASTER_OPTIONS:MGTK3}
LIB_DEPENDS+=	libcanberra-gtk3.so:audio/libcanberra-gtk3
.endif

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
