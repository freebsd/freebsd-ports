PORTNAME=	fancy

COMMENT=	Webkit based HTML renderer plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugins.php

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
