# New ports collection makefile for:	py-pylons
# Date created:		Thu Jun 21 16:05:21 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	pylons
PORTVERSION=	0.9.6.2
CATEGORIES=	www python
MASTER_SITES=	http://pylonshq.com/download/0.9.6.2/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Pylons Web Framework

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=1.3:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.3.2:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}beaker>=0.6.3:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}decorator>=2.0.1:${PORTSDIR}/devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}formencode>=0.7:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}mako>=0.1.5:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}nose>=0.9.2:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}routes>=1.6.3:${PORTSDIR}/www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.7.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.3.2:${PORTSDIR}/www/py-webhelpers \
		myghty>=1.1:${PORTSDIR}/www/myghty

USE_PYTHON=	2.5
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	Pylons
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} \
		-type d -exec ${CHMOD} 755 {} +
	${FIND} ${PYTHON_SITELIBDIR}/${PYEASYINSTALL_EGG} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} +

.include <bsd.port.mk>
