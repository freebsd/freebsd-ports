PORTNAME=	flask-mail
PORTVERSION=	0.10.0
CATEGORIES=	mail www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	flask_mail-${DISTVERSION}

MAINTAINER=	john@saltant.com
COMMENT=	Send SMTP email from a Flask web application
WWW=		https://flask-mail.readthedocs.io/ \
		https://github.com/pallets-eco/flask-mail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

PEP517_BUILD_DEPEND=	${PYTHON_PKGNAMEPREFIX}flit-core>=0:devel/py-flit-core@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
PEP517_BUILD_CMD=	${PYTHON_CMD} -m flit_core.wheel

NO_ARCH=	yes

.include <bsd.port.mk>
