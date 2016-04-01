# Created by: James Earl
# $FreeBSD$

PORTNAME=	xmlroff
PORTVERSION=	0.6.2
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	http://xmlroff.org/download/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XSL formatter that produces PDF and PostScript

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcairo.so:graphics/cairo

USES=		gmake libtool pkgconfig pathfix
USE_GNOME=	libgnomeprint libxslt \
		libxml2 gtk20 glib20 pango
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/libfo/fo-libfo-basic.h

.include <bsd.port.mk>
