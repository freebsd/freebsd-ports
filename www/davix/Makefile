PORTNAME=	davix
DISTVERSIONPREFIX=	R_
DISTVERSION=	0_9_0
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Make the task of managing files over HTTP-based protocols simple
WWW=		https://dmc-docs.web.cern.ch/dmc-docs/davix.html \
		https://github.com/cern-fts/davix

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/libuuid
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake:testing compiler:c++17-lang gnome localbase:ldflags python:build shebangfix ssl
SHEBANG_GLOB=	*.py
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cern-fts

CMAKE_OFF=	EMBEDDED_LIBCURL DAVIX_TESTS
CMAKE_TESTING_ON=	DAVIX_TESTS UNIT_TESTS BENCH_TESTS

TESTING_UNSAFE=	1 test fails, and several tests hang, see https://github.com/cern-fts/davix/issues/108

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^[0-9\.]*$$ # prevent versions like N.N.N-el7.x86_64

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

# tests as of 0.8.8: tests freeze, see https://github.com/cern-fts/davix/issues/133
# tests as of 0.9.0: same freeze, upstream doesn't seem to care

.include <bsd.port.mk>
