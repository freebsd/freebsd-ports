# $FreeBSD$

CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for miniupnpc

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libminiupnpc.so:${PKGCATEGORY}/miniupnpc

MASTERDIR=	${.CURDIR}/../miniupnpc

USES=		python
USE_PYTHON=	autoplist distutils
MAKE_ENV=	MAKE=gmake
PLIST=

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/miniupnpc.so

.include "${MASTERDIR}/Makefile"
