PORTNAME=	pyhanko-certvalidator
PORTVERSION=	0.28.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyhanko_certvalidator-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Validates X.509 certificates and paths
WWW=		https://github.com/MatthiasValvekens/pyHanko/tree/master/pkgs/pyhanko-certvalidator \
		https://github.com/MatthiasValvekens/pyHanko

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=1.5.1:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oscrypto>=1.1.0:security/py-oscrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritools>=3.0.1:net/py-uritools@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	ASYNC_HTTP
ASYNC_HTTP_DESC=Asynchronous support

ASYNC_HTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9<3.13:www/py-aiohttp@${PY_FLAVOR}

.include <bsd.port.mk>
