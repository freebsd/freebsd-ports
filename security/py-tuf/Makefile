PORTNAME=	tuf
DISTVERSION=	5.0.0
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for securing software update systems
WWW=		https://www.updateframework.com

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.13.0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.19.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}securesystemslib>=1.0:security/py-securesystemslib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

PYTEST_BROKEN_TESTS=	test_cleanup TestRepoExamples # uses files missing from pypi distribution

post-patch:
	@${REINPLACE_CMD} 's|hatchling==1|hatchling>=1|g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
