# Created by: Wen Heping <wen@FreeBSD.org>

PORTNAME=	mdal
DISTVERSION=	0.8.1
CATEGORIES=	math geography

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Mesh data abstration library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/gtest/gtest.h:devel/googletest
LIB_DEPENDS=	libpdal_base.so:math/pdal \
		libnetcdf.so:science/netcdf \
		libsqlite3.so:databases/sqlite3

USES=		cmake localbase
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

.include <bsd.port.mk>
