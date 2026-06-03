PORTNAME=	libxspf
DISTVERSION=	1.2.1
CATEGORIES=	multimedia
MASTER_SITES=	SF/libspiff/Sources/${DISTVERSION}

MAINTAINER=	ed@FreeBSD.org
COMMENT=	XSPF parsing library
WWW=		https://libspiff.sourceforge.net/

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		liburiparser.so:net/uriparser

LICENSE=	BSD3CLAUSE

USES=		libtool localbase:ldflags pkgconfig tar:bzip2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-static \
		--disable-test \
		--with-pkgconfigdir=${LOCALBASE}/libdata/pkgconfig

.include <bsd.port.mk>
