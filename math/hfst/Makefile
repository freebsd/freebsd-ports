# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hfst
PORTVERSION=	3.8.2
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/source

PATCH_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES=	134d5a5aac3f.patch:-p1

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A toolkit for for processing natural language morphologies

USES=		libtool pathfix pkgconfig python:2 readline shebangfix
USE_GNOME=	glib20 libxml2
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline --with-unicode-handler=glib --enable-calculate --enable-edit-metadata --enable-lexc-wrapper --enable-proc --enable-tagger --enable-xfst --enable-shuffle --enable-traverse
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	tools/src/hfst-tagger/src/hfst_tagger_compute_data_statistics.py
USE_LDCONFIG=	yes

.include <bsd.port.mk>
