PORTNAME=	aiocoap
PORTVERSION=	0.4.17
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python CoAP library
WWW=		https://aiocoap.readthedocs.io/en/latest/ \
		https://codeberg.org/aiocoap/aiocoap

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	dual
LICENSE_FILE_BSD3CLAUS=	${WRKSRC}/LICENSES/BSD-3-Clause.txt
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
