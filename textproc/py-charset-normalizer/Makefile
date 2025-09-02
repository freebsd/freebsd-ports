PORTNAME=	charset-normalizer
PORTVERSION=	3.4.3
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
