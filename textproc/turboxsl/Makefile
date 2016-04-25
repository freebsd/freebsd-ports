# $FreeBSD$

PORTNAME=	turboxsl
PORTVERSION=	0.0.899004eb7b
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Fast, multithreaded XML+XSLT transformation library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libmemcached.so:databases/libmemcached

ONLY_FOR_ARCHS=	amd64 ia64 powerpc64 sparc64
USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Litres
GH_TAGNAME=	899004eb7b
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
