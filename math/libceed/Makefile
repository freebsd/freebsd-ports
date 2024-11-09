PORTNAME=	libceed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0-763
DISTVERSIONSUFFIX=	-ge3ae47f6
CATEGORIES=	math # machine-learning

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

TEST_TARGET=	test # tests fail, see https://github.com/CEED/libCEED/issues/1705

BINARY_ALIAS=	python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libceed.so

.include <bsd.port.mk>
