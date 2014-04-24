# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libcroco
PORTVERSION=	0.6.8
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	CSS2 parsing library

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 libxml2 ltverhack
USES=		pkgconfig gettext gmake
CONFIGURE_ARGS=	--disable-gtk-doc-html

PLIST_SUB=	VERSION="0.6"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900035
CONFIGURE_ARGS+=--disable-Bsymbolic
.endif

.include <bsd.port.post.mk>
