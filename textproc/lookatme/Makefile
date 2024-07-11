PORTNAME=	lookatme
PORTVERSION=	2.5.5
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Interactive, terminal-based markdown presenter
WWW=		https://github.com/d0c-s4vage/lookatme

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}marshmallow>=0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistune0>=0.8<1:textproc/py-mistune0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist distutils noflavors pytest
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|>.*||' ${WRKSRC}/requirements.txt

.include <bsd.port.mk>
