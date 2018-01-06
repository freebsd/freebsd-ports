# $FreeBSD$

CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python module for miniupnpc

BUILD_DEPENDS=	${NONEXISTENT}:net/miniupnpc:build

MASTERDIR=	${.CURDIR}/../miniupnpc

USES=		python
USE_PYTHON=	autoplist distutils

PLIST=		${.CURDIR}/pkg-plist

post-patch:
	${REINPLACE_CMD} 's/\(version\)="[^"]*"/\1="${PORTVERSION}"/' \
		${WRKSRC}/setup.py

pre-build:
	${CP} $$(${SETENV} -u FLAVOR make -C ${MASTERDIR} -V WRKSRC)/libminiupnpc.a ${WRKSRC}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/miniupnpc.so

.include "${MASTERDIR}/Makefile"
