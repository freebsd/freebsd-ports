PORTNAME=	Flask-Admin
PORTVERSION=	1.6.1
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Flask extension for adding admin interfaces to Flask applications
WWW=		https://github.com/flask-admin/flask-admin/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0.10:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wtforms>0:textproc/py-wtforms@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
