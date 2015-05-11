# $FreeBSD$

CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings to CryptoMiniSat

LICENSE=	MIT

LIB_DEPENDS=	libcryptominisat4.so:${PORTSDIR}/math/cryptominisat

USES=		compiler:c++11-lib python:2.7 tar:bzip2
USE_PYTHON=	autoplist distutils
WRKSRC_SUBDIR=	python

MASTERDIR=	${.CURDIR}/../cryptominisat
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name \*.so \
		-exec ${STRIP_CMD} {} +

.include "${MASTERDIR}/Makefile"
