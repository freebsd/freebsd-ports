PORTNAME=	pystemmer
PORTVERSION=	3.1.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		http://snowball.tartarus.org/wrappers/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Snowball Stemming Algorithms for Information Retrieval
WWW=		https://pypi.org/project/PyStemmer/

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=18.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libstemmer.so:textproc/snowballstemmer

USES=		python
USE_PYTHON=	autoplist cython pep517 pytest
CONFIGURE_ENV+=	PYSTEMMER_SYSTEM_LIBSTEMMER=1
MAKE_ENV+=	PYSTEMMER_SYSTEM_LIBSTEMMER=1
CFLAGS+=	-I${LOCALBASE}/include

post-install:
.ifndef WITH_DEBUG
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Stemmer.*.so
.endif

.include <bsd.port.mk>
