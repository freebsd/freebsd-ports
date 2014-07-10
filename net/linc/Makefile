# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	linc
PORTVERSION=	1.0.3
PORTREVISION?=	7
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for writing networked servers & clients

USE_BZIP2=	yes

.if !defined(REFERENCE_PORT)

USES=		pkgconfig gmake
USE_GNOME=	gnomehack glib20
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include -DGLIB_COMPILATION
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
