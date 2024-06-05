PORTNAME=	fancy

COMMENT=	Webkit based HTML renderer plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugins.php

LIB_DEPENDS=	libcurl.so:ftp/curl

.include "../claws-mail/Makefile.ver"

.if ${MASTER_OPTIONS:MGTK2}
IGNORE=		depends on www/webkit-gtk2, which has been removed
.endif
.if ${MASTER_OPTIONS:MGTK3}
LIB_DEPENDS+=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
.endif

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
