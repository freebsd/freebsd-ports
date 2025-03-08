PORTNAME=	stem
PORTVERSION=	1.8.2
PORTREVISION=	1
CATEGORIES=	security net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Python controller library for Tor
WWW=		https://stem.torproject.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyflakes>0:devel/py-pyflakes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycodestyle>0:devel/py-pycodestyle@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} run_tests.py -a

.include <bsd.port.mk>
