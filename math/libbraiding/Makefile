PORTNAME=	libbraiding
DISTVERSION=	1.3.1
CATEGORIES=	math
MASTER_SITES=	https://github.com/miguelmarco/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library for computations on braid groups
WWW=		https://github.com/jeanluct/braidlab

LICENSE=	GPLv3

USES=		compiler:c++17-lang libtool pkgconfig
USE_CXXSTD=	c++17
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
