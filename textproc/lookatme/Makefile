PORTNAME=	lookatme
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Interactive, terminal-based markdown presenter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>=0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune>=0:textproc/py-mistune@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR}

USES=		cpe python:3.6+ pytest
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

# https://github.com/d0c-s4vage/lookatme/issues/126
PYTEST_BROKEN_TESTS=	test_sanity_check_that_errors_are_detected \
			test_styles_defaults

post-patch:
	@${REINPLACE_CMD} -e 's|>.*||' ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
