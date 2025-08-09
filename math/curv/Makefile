PORTNAME=	curv
DISTVERSION=	0.5
PORTREVISION=	26
CATEGORIES=	math lang graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Language for making art using mathematics
WWW=		https://curv3d.org/ \
		https://codeberg.org/doug-moen/curv

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !exists(/usr/include/omp.h)
BROKEN=		requires OpenMP support that is missing on this architecture
.endif

BUILD_DEPENDS=	glm>0:math/glm
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libdouble-conversion.so:devel/double-conversion \
		libglfw.so:graphics/glfw \
		libImath.so:math/Imath \
		libtbb.so:devel/onetbb \
		libopenvdb.so:misc/openvdb

USES=		cmake compiler:c++14-lang gl localbase:ldflags xorg
USE_GL=		gl
USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	curv3d
GH_TUPLE=	ocornut:imgui:e0cab56:imgui/extern/imgui \
		Tessil:ordered-map:4051af7:om/extern/ordered-map \
		AmokHuginnsson:replxx:b901d5f:replxx/extern/replxx

LDFLAGS+=	-lopenvdb

PLIST_FILES=	bin/curv \
		lib/curv/lib/blend.curv \
		lib/curv/lib/builder.curv \
		lib/curv/lib/noise.curv \
		lib/curv/lib/web_colour.curv \
		lib/curv/std.curv \
		share/gtksourceview-3.0/language-specs/curv.lang

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/curv/lib/README

.include <bsd.port.mk>
