PORTNAME=	bout++-merging-filaments
DISTVERSION=	g20200812
PORTREVISION=	3
CATEGORIES=	science # physics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulation of reconnection during merging of current filaments
WWW=		https://github.com/boutproject/merging-filaments

LICENSE=	GPLv3 # based on the parent project BOUT++

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libbout++.so:science/bout++ \
		libfftw3.so:math/fftw3 \
		libfmt.so:devel/libfmt \
		libmpi.so:net/mpich \
		libnetcdf.so:science/netcdf \
		libnetcdf_c++4.so:science/netcdf-cxx \
		libuuid.so:misc/libuuid

USES=		cmake:testing gettext
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	boutproject
GH_PROJECT=	merging-filaments
GH_TAGNAME=	ee5a7b9

BINARY_ALIAS=	make=${GMAKE}

PLIST_FILES=	bin/merging-flux

post-patch:
	@${CP} ${FILESDIR}/CMakeLists.txt ${WRKSRC}

.include <bsd.port.mk>
