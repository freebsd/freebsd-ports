# $FreeBSD$

PORTNAME=	curv
DISTVERSION=	0.4-87
DISTVERSIONSUFFIX=	-g947ca71e
CATEGORIES=	math lang graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for making art using mathematics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm \
		replxx>0:devel/replxx
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libglfw.so:graphics/glfw \
		libHalf.so:graphics/ilmbase \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++14-lang gl localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	curv3d
GH_TUPLE=	ocornut:imgui:e0cab5664adf02c030f9cf2a05d2c334638a85f8:imgui/extern/imgui \
		Tessil:ordered-map:3c1415148f38409e4e68c13c55117107ece0187d:om/extern/ordered-map
USE_GL=		gl
USE_XORG=	x11

PLIST_FILES=	bin/curv \
		lib/curv/lib/blend.curv \
		lib/curv/lib/web_colour.curv \
		lib/curv/std.curv \
		share/gtksourceview-3.0/language-specs/curv.lang

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/curv/lib/README

.include <bsd.port.mk>
