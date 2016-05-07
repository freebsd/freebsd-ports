# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	pylons
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	http://pylonshq.com/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python based web framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.3:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.3:www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.3:www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}decorator>=2.3.2:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.1:www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}mako>=0.2.4:textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}nose>=0.10.4:devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}routes>=1.12:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.8:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:www/py-webhelpers \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.1:www/py-WebError \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.1:www/py-WebTest \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.2:textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.4.4:textproc/py-genshi
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
