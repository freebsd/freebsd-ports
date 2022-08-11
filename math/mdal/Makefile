PORTNAME=	mdal
DISTVERSION=	0.9.4
PORTREVISION=	2
CATEGORIES=	math geography

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Mesh data abstration library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/gtest/gtest.h:devel/googletest
LIB_DEPENDS=	libpdal_base.so:math/pdal \
		libnetcdf.so:science/netcdf \
		libsqlite3.so:databases/sqlite3 \
		libgdal.so:graphics/gdal \
		libhdf5.so:science/hdf5 \
		libsz.so:science/libaec

USES=		cmake gnome localbase
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PLIST_FILES=	bin/mdal_translate \
		bin/mdalinfo \
		include/mdal.h \
		lib/libmdal.so \
		lib/libmdal_a.a

USE_GITHUB=	yes
GH_ACCOUNT=	lutraconsulting
GH_PROJECT=	MDAL
GH_TAGNAME=	release-${DISTVERSION}

CMAKE_ARGS=	-DSQLITE3_INCLUDE_DIRS="${LOCALBASE}/include" \
		-DSQLITE3_LIBRARY="${LOCALBASE}/lib/libsqlite3.so"

.include <bsd.port.mk>
