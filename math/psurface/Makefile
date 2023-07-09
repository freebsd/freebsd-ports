PORTNAME=	psurface
DISTVERSION=	2.0.0-13
DISTVERSIONSUFFIX=	-gb5b6825
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Piecewise linear bijections between triangulated surfaces
WWW=		https://github.com/psurface/psurface

LICENSE=	GPLv3+

LIB_DEPENDS=	libhdf5.so:science/hdf5

USES=		autoreconf libtool localbase
USE_CXXSTD=	c++14 # fix compilation failure on 14 due to use of std::auto_ptr that was deprecated in C++17
USE_LDCONFIG=	yes

USE_GITHUB=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

TEST_TARGET=	check # 2 tests fail because the file examplefiles/tricube-anticlockwise.msh is missing, see https://github.com/psurface/psurface/issues/3

.include <bsd.port.mk>
