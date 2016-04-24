# Created by: Loic Blot <loic.blot@unix-experience.fr>
# $FreeBSD$

PORTNAME=	searx
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lblot@unix-experience.fr
COMMENT=	Searx / a privacy-respecting, hackable metasearch engine

LICENSE=	AGPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}Flask-Babel>0:devel/py-flask-babel \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}Flask>0:www/py-flask \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug

USE_RC_SUBR=	searx

USE_GITHUB=	yes
GH_ACCOUNT=	asciimoo
GH_PROJECT=	searx

USES=		python
USE_PYTHON=	autoplist distutils concurrent

.include <bsd.port.mk>
