# $FreeBSD$

PORTNAME=	turboxsl
DISTVERSION=	b03c2c9
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Fast, multithreaded XML+XSLT transformation library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libmemcached.so:databases/libmemcached

BROKEN_powerpc64=	Does not build
ONLY_FOR_ARCHS=	amd64 ia64 powerpc64 sparc64
USES=		autoreconf libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Litres
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
