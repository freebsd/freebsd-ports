PORTNAME=	tuf
PORTVERSION=	1.1.0
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for securing software update systems

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.19.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}securesystemslib>=0.22.0:security/py-securesystemslib@${PY_FLAVOR}

USES=		pytest python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PYTEST_BROKEN_TESTS=	test_cleanup TestRepoExamples # uses files missing from pypi distribution

post-patch:
	@${RM} ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
