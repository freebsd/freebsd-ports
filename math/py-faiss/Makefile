PORTNAME=	faiss
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for efficient similarity search & clustering of dense vectors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../LICENSE

PY_DEPENDS=	${PYNUMPY}
BUILD_DEPENDS=	swig:devel/swig \
		${PY_DEPENDS}
LIB_DEPENDS=	libfaiss.so:math/faiss
RUN_DEPENDS=	${PY_DEPENDS}

USES=		cmake compiler:c++11-lang localbase python

USE_GITHUB=	yes
GH_ACCOUNT=	facebookresearch

WRKSRC_SUBDIR=	faiss/python

PLIST_FILES=	\
		${PYTHON_SITELIBDIR}/${PORTNAME}/_swigfaiss.so \
		${PYTHON_SITELIBDIR}/${PORTNAME}/__init__.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/loader.py \
		${PYTHON_SITELIBDIR}/${PORTNAME}/swigfaiss.py

do-install: # see https://github.com/facebookresearch/faiss/issues/2194
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
	${INSTALL_LIB} ${BUILD_WRKSRC}/_swigfaiss.so ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.for f in __init__.py loader.py swigfaiss.py
	${INSTALL_DATA} ${BUILD_WRKSRC}/${f} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}
.endfor

do-test: install
	@${PYTHON_CMD} ${FILESDIR}/test.py

.include <bsd.port.mk>
