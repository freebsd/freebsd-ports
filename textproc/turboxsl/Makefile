PORTNAME=	turboxsl
DISTVERSION=	b03c2c9
PORTEPOCH=	1
CATEGORIES=	textproc

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Fast, multithreaded XML+XSLT transformation library
WWW=		https://github.com/Litres/turboxsl

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 powerpc64 powerpc64le

LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libmemcached.so:databases/libmemcached

USES=		autoreconf libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	Litres

GNU_CONFIGURE=	yes
CFLAGS+=	-fcommon
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
