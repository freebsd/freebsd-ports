# $FreeBSD$

PORTNAME=	curv
DISTVERSION=	0.4-333
DISTVERSIONSUFFIX=	-ga9a63930
PORTREVISION=	1
CATEGORIES=	math lang graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for making art using mathematics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libglfw.so:graphics/glfw \
		libHalf.so:graphics/ilmbase \
		libopenvdb.so:misc/openvdb \
		libtbb.so:devel/tbb

USES=		cmake compiler:c++14-lang gl localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	curv3d
GH_TUPLE=	ocornut:imgui:e0cab56:imgui/extern/imgui \
		Tessil:ordered-map:3c14151:om/extern/ordered-map \
		AmokHuginnsson:replxx:9da16bb:replxx/extern/replxx
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
