PORTNAME=	ascii-magic
DISTVERSION=	2.7.5
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convert pictures into ASCII art
WWW=		https://github.com/LeandroBarone/python-ascii_magic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/ascii_magic/tests

# tests as of 2.7.5: 28 passed, 3 skipped in 5.84s

.include <bsd.port.mk>
