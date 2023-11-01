PORTNAME=	libbraiding
PORTVERSION=	1.2
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	C++ library for computations on braid groups
WWW=		https://github.com/jeanluct/braidlab

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	miguelmarco

USES=		autoreconf  compiler:c++11-lang libtool

CXXFLAGS+=	-std=c++17
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
