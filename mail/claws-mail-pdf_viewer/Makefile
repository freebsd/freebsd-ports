# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	pdf_viewer
PORTREVISION=	9

COMMENT=	PDF and PostScript viewer plugin for Claws Mail

LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib

USES+=		ghostscript

CLAWS_PLUGINS_BUILD=	${PORTNAME}

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
