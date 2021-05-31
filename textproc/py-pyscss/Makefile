# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>

PORTNAME=	pyscss
PORTVERSION=	1.3.7
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Compiler for SCSS flavor of the Sass language

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}
LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Kronuz
GH_PROJECT=	pyScss

USES=		python:3.6+ localbase:ldflags
USE_PYTHON=	distutils autoplist

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
