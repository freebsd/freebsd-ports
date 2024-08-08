PORTNAME=	tomlkit
PORTVERSION=	0.13.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		https://github.com/sdispater/tomlkit/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Style-preserving TOML library
WWW=		https://tomlkit.readthedocs.io/en/latest/ \
		https://github.com/python-poetry/tomlkit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

SHEBANG_FILES=	tests/toml-test/gen-multi.py

post-patch:
	@${MV} ${WRKSRC}/tests ${WRKSRC}/tomlkit

.include <bsd.port.mk>
