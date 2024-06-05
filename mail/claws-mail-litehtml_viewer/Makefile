PORTNAME=	litehtml_viewer

COMMENT=	Viewer plugin for HTML emails, using the litehtml library
WWW=		https://www.claws-mail.org/plugins.php

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgumbo.so:devel/gumbo \
		libcurl.so:ftp/curl

USE_GNOME=	cairo glib20

# The configure script does not set REAL_CXX if CXX contains an absolute path.
CONFIGURE_ENV=	REAL_CXX="${CXX}"

CLAWS_PLUGINS_BUILD=	${PORTNAME}

post-configure:
	@${RM} ${WRKSRC}/version

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
