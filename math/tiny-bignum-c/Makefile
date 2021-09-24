PORTNAME=	tiny-bignum-c
DISTVERSION=	g20210222
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Small portable multiple-precision unsigned integer arithmetic in C

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:build,test # build only for BINARY_ALIAS
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	kokke
GH_TAGNAME=	201fb20

ENAME=		bignum # libbn.so is used by another package, so install it as bignum

TEST_TARGET=	all test # some tests fail, see https://github.com/kokke/tiny-bignum-c/issues/29

BINARY_ALIAS=	python=${PYTHON_CMD}

PLIST_FILES=	include/${ENAME}.h \
		lib/lib${ENAME}.a \
		lib/lib${ENAME}.so

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${CC} -c ${CFLAGS} bn.c && \
		${AR} -cq lib${ENAME}.a bn.o && \
		${SETENV} ${MAKE_ENV} ${CC} -c ${CFLAGS} -fPIC bn.c && \
		${CC} -shared -o lib${ENAME}.so -Wl,-soname,lib${ENAME}.so ${LDFLAGS} bn.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/bn.h ${STAGEDIR}${PREFIX}/include/${ENAME}.h
	${INSTALL_DATA} ${WRKSRC}/lib${ENAME}.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib${ENAME}.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
