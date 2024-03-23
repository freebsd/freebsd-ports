PORTNAME=	davix
DISTVERSIONPREFIX=	R_
DISTVERSION=	0_8_5
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Make the task of managing files over HTTP-based protocols simple
WWW=		https://dmc-docs.web.cern.ch/dmc-docs/davix.html

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		cmake:testing compiler:c++11-lang gnome localbase:ldflags python:build shebangfix ssl
SHEBANG_GLOB=	*.py
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	cern-fts
GH_TUPLE=	google:googletest:f570b27:googletest/deps/googletest

CMAKE_OFF=	EMBEDDED_LIBCURL DAVIX_TESTS
CMAKE_TESTING_ON=	DAVIX_TESTS UNIT_TESTS BENCH_TESTS # 1 test fails, and several tests hang, see https://github.com/cern-fts/davix/issues/108

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^[0-9\.]*$$ # prevent versions like N.N.N-el7.x86_64

post-install:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
