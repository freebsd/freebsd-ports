# Created by: Rozhuk Ivan <rozhuk.im@gmail.com>
# $FreeBSD$

PORTNAME=	litehtml_viewer

COMMENT=	Viewer plugin for HTML emails, using the litehtml library

USE_GNOME=	cairo glib20 
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgumbo.so:devel/gumbo \
		libcurl.so:ftp/curl

CLAWS_PLUGINS_BUILD=	${PORTNAME}

post-configure:
	@${RM} ${WRKSRC}/version

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
