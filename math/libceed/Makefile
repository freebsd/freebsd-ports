PORTNAME=	libceed
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CEED Library: Code for Efficient Extensible Discretizations
WWW=		https://libceed.org/en/latest/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fortran gmake python:build,test
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	CEED
GH_PROJECT=	libCEED

CFLAGS+=	-fPIC # https://github.com/CEED/libCEED/issues/1706
FFLAGS+=	-cpp # needed for the Fortran tests that use the SOURCE_DIR macro

TEST_TARGET=	test

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libceed.so

# tests as of 1.1.0: ok

.include <bsd.port.mk>
