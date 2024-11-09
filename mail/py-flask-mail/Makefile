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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=0<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.9:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=0:devel/py-blinker@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
