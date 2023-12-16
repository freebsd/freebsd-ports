PORTNAME=	cryptography-vectors
PORTVERSION=	41.0.7
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cryptography_vectors-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test vectors for the cryptography package
WWW=		https://cryptography.io/en/latest/development/test-vectors/ \
		https://github.com/pyca/cryptography/tree/main/vectors

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
