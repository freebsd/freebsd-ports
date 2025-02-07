PORTNAME=	niquests
PORTVERSION=	3.12.3
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/jawah/niquests/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, yet elegant, HTTP library
WWW=		https://niquests.readthedocs.io/en/stable/ \
		https://github.com/jawah/niquests

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.6.0<2:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2<4:textproc/py-charset-normalizer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5<4:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kiss-headers>=2<4:www/py-kiss-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3-future>=2.12.900<3:net/py-urllib3-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wassima>=1.0.1<2:security/py-wassima@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
