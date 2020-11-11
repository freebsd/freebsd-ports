# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	pylons
PORTVERSION=	1.0.3
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python based web framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-12-12

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.15:textproc/py-MarkupSafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.7.5.1:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pastedeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.4.2:www/py-pastescript@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.5.1:textproc/py-Tempita@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.3:www/py-WebError@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.3.1:www/py-WebTest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.5.4:www/py-beaker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.3.2:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.5.0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=1.12.3:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.1:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.1.1:www/py-webob@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.2.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
