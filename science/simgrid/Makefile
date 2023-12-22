PORTNAME=	SimGrid
DISTVERSIONPREFIX=	v
DISTVERSION=	3.35
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simulator of the behavior of large-scale distributed systems
WWW=		https://simgrid.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE-LGPL-2.1

LIB_DEPENDS=	libboost_context.so:devel/boost-libs \
		libcgraph.so:graphics/graphviz \
		libevent.so:devel/libevent \
		${LIB_DEPENDS_${ARCH}}

USES=		cmake:testing compiler:c++14-lang perl5 python shebangfix
SHEBANG_FILES=	tools/simgrid_convert_TI_traces.py
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://framagit.org/
GL_ACCOUNT=	simgrid
GL_PROJECT=	simgrid
GL_TAGNAME=	d68e1c39ec0832cb2391aedd17a868c597dd399e

CMAKE_OFF=	enable_python

LDFLAGS+=	/usr/lib/liblzma.so # workaround for https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=237919

# it'll probably break on gcc-based systems, see https://framagit.org/simgrid/simgrid/issues/12, it'll need CMAKE_OFF=enable_lto and possibly more

# tests fail, see https://github.com/simgrid/simgrid/issues/384

pre-test: # build tests
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} tests

.include <bsd.port.mk>
