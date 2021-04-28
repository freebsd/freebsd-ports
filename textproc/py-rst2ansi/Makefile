PORTNAME=	rst2ansi
PORTVERSION=	0.1.5
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	PopularMoment@protonmail.com
COMMENT=	RST converter to ansi-decorated console output

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.14:textproc/py-docutils@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC}/ && ${PYTHON_CMD} setup.py test

.include <bsd.port.mk>
