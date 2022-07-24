PORTNAME=	SimGrid
DISTVERSION=	3.31
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator of the behavior of large-scale distributed systems

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE-LGPL-2.1

LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libcgraph.so:graphics/graphviz \
		${LIB_DEPENDS_${ARCH}}

USES=		cmake:noninja compiler:c++14-lang perl5 python:3.6+ shebangfix
SHEBANG_FILES=	tools/simgrid_convert_TI_traces.py
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://framagit.org/
GL_ACCOUNT=	simgrid
GL_PROJECT=	simgrid
GL_COMMIT=	fcfdefe62e01e5353377ebe3573782ba4d368eeb

CMAKE_OFF=	enable_python

LDFLAGS+=	/usr/lib/liblzma.so # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=237919

# it'll probably break on gcc-based systems, see https://framagit.org/simgrid/simgrid/issues/12, it'll need CMAKE_OFF=enable_lto and possibly more

.include <bsd.port.mk>
