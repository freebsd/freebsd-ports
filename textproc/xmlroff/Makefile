# New ports collection makefile for:	xmlroff
# Date created:		1 January 2005
# Whom:			James Earl
#
# $FreeBSD$
#

PORTNAME=	xmlroff
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://xmlroff.org/download/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter that produces PDF and PostScript

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget libgnomeprint libxslt \
		libxml2 gtk20 glib20 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
