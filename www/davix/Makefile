PORTNAME=	davix
DISTVERSION=	0.7.6
CATEGORIES=	www
MASTER_SITES=	http://grid-deployment.web.cern.ch/grid-deployment/dms/lcgutil/tar/${PORTNAME}/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Make the task of managing files over HTTP-based protocols simple

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake compiler:c++11-lang gnome localbase:ldflags python:build shebangfix ssl
SHEBANG_GLOB=	*.py
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^[0-9\.]*$$ # prevent versions like N.N.N-el7.x86_64

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

do-test: # tests are known to fail: https://github.com/cern-fts/davix/issues/33
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DUNIT_TESTS=ON FUNCTIONAL_TESTS=ON BENCH_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
