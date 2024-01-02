PORTNAME=	pdf_viewer
PORTREVISION=	2

COMMENT=	PDF and PostScript viewer plugin for Claws Mail
WWW=		https://www.claws-mail.org/plugin.php?plugin=pdf_viewer

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USES+=		ghostscript

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
