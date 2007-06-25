# New ports collection makefile for:	py-pylons
# Date created:		Thu Jun 21 16:05:21 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	pylons
PORTVERSION=	0.9.5
CATEGORIES=	www python
MASTER_SITES=	http://pylonshq.com/download/0.9.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pylons-${PORTVERSION}

MAINTAINER=	dsh@vlink.ru
COMMENT=	Pylons Web Framework

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}Paste>=1.3:${PORTSDIR}/www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.3:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.3.2:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}beaker>=0.6.3:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}decorator>=2.0.1:${PORTSDIR}/devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}formencode>=0.7:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}mako>=0.1.5:${PORTSDIR}/textproc/py-mako \
		${PYTHON_PKGNAMEPREFIX}nose>=0.9.2:${PORTSDIR}/devel/py-nose \
		${PYTHON_PKGNAMEPREFIX}routes>=1.6.3:${PORTSDIR}/www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.7.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}webhelpers>=0.3:${PORTSDIR}/www/py-webhelpers \
		myghty>=1.1:${PORTSDIR}/www/myghty

USE_PYTHON=	2.4
USE_PYDISTUTILS=	yes

PYPYLONS_EGG=	Pylons-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYPYLONS_EGG=${PYPYLONS_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

DOCSDIR=	${TARGETDIR}/share/doc/py-${PORTNAME}

post-install:
	${FIND} ${PYTHON_SITELIBDIR}/${PYPYLONS_EGG} \
		-type d -exec ${CHMOD} 755 {} +
	${FIND} ${PYTHON_SITELIBDIR}/${PYPYLONS_EGG} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} +

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.include <bsd.port.mk>
