PORTNAME=	rdap
PORTVERSION=	1.7.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Registration Data Access Protocol tools
WWW=		https://github.com/20c/rdap

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}googlemaps>=4:www/py-googlemaps@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}munge>=1:devel/py-munge@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonenumbers>=8:devel/py-phonenumbers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
