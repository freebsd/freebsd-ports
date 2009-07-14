# New ports collection makefile for:	py-pylons
# Date created:		Thu Jun 21 16:05:21 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	pylons
PORTVERSION=	0.9.7
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	http://pylonshq.com/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Pylons Web Framework

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.7.2:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3.3:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.3:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}beaker>=1.2.2:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}decorator>=2.3.2:${PORTSDIR}/devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.1:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}mako>=0.2.4:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}nose>=0.10.4:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}routes>=1.10.3:${PORTSDIR}/www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.8:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.6.4:${PORTSDIR}/www/py-webhelpers \
		${PYTHON_PKGNAMEPREFIX}WebError>=0.10.1:${PORTSDIR}/www/py-WebError \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.6.1:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}WebTest>=1.1:${PORTSDIR}/www/py-WebTest \
		${PYTHON_PKGNAMEPREFIX}Tempita>=0.2:${PORTSDIR}/textproc/py-Tempita \
		${PYTHON_PKGNAMEPREFIX}docutils>=0.4:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.4.4:${PORTSDIR}/textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}pygments>=0.7:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}TurboCheetah>=0.9.5:${PORTSDIR}/devel/py-turbocheetah \
		${PYTHON_PKGNAMEPREFIX}kid>=0.9:${PORTSDIR}/devel/py-kid \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=0.9.1:${PORTSDIR}/devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}cheetah>=2.0.1:${PORTSDIR}/devel/py-cheetah
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Pylons
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
