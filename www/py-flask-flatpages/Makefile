PORTNAME=	Flask-FlatPages
PORTVERSION=	0.6
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	oleg@bsdpower.com
COMMENT=	Provides flat static pages to a Flask application
WWW=		https://github.com/SimonSapin/Flask-FlatPages

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}  \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
