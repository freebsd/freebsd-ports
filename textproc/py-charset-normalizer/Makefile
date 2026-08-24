PORTNAME=	charset-normalizer
PORTVERSION=	3.5.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/jawah/charset_normalizer/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	charset_normalizer-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Real First Universal Charset Detector
WWW=		https://charset-normalizer.readthedocs.io/en/latest/ \
		https://github.com/Ousret/charset_normalizer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61<84.1:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython pep517

MAKE_ENV=	CHARSET_NORMALIZER_CYTHON_ABI3=0 \
		CHARSET_NORMALIZER_USE_CYTHON=1

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
