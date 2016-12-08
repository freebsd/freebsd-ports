# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libxspf
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/libspiff/Sources/${PORTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	XSPF parsing library

LIB_DEPENDS=	libexpat.so:textproc/expat2

# We need 0.7.5, which uses pkg-config
BUILD_DEPENDS=	uriparser>=0.7.5:net/uriparser
RUN_DEPENDS=	uriparser>=0.7.5:net/uriparser

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-expat=${LOCALBASE} --disable-test

USES=		libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
LIBS+=		-L${LOCALBASE}/lib -luriparser

post-patch:
	@${REINPLACE_CMD} 's|$$(libdir)/pkgconfig|$$(libdir)data/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
