PORTNAME=	pyreadr
PORTVERSION=	0.5.9
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read/write R RData and Rds files into/from pandas data frames
WWW=		https://github.com/ofajardo/pyreadr

LICENSE=	AGPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	librdata.so:math/librdata
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}narwhals>=2.26.0:math/py-narwhals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		iconv localbase python
USE_PYTHON=	autoplist concurrent cython pep517

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/pyreadr/libs/
	@${RM} -r ${WRKSRC}/win_libs/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
