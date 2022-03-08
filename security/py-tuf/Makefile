# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	tuf
PORTVERSION=	0.11.1
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for securing software update systems

LICENSE=	MIT APACHE20
LICENSE_COMB=	dual
#LICENSE_FILE=	Not packaged in PyPI sdist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.12:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}securesystemslib>=0.11.2:security/py-securesystemslib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

# Actually 2.6-3.5
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

# https://github.com/theupdateframework/tuf/pull/781#discussion_r221880421
post-patch:
	${REINPLACE_CMD} -e \
		"s|'python',|sys.executable,|g" \
		${WRKSRC}/tests/*.py

do-test:
	@cd ${WRKSRC}/tests && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
