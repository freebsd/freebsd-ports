# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	pylons
PORTVERSION=	1.0.2
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python based web framework

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}routes>=1.12.3:www/py-routes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.5.4:www/py-beaker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.7.5.1:www/py-paste@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.4.2:www/py-pastescript@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.4:www/py-formencode@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.1:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.3.2:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=1.1.2:devel/py-nose@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0.5.0:textproc/py-mako@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.3:www/py-WebError@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.3.1:www/py-WebTest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.5.1:textproc/py-Tempita@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.15:textproc/py-MarkupSafe@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.1.1:www/py-webob@${FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
