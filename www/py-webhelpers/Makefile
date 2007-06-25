# New ports collection makefile for:	py-webhelpers
# Date created:		Thu Jun 21 12:44:46 MSD 2007
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $FreeBSD$
#

PORTNAME=	webhelpers
PORTVERSION=	0.3
CATEGORIES=	www python
MASTER_SITES=	http://pylonshq.com/download/0.9.5/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebHelpers-${PORTVERSION}

MAINTAINER=	dsh@vlink.ru
COMMENT=	A Python helper functions for writing templates in web applications easier

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}routes>=1.1:${PORTSDIR}/www/py-routes \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.4:${PORTSDIR}/devel/py-simplejson

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	yes

PYWEBHELPERS_EGG=	WebHelpers-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYWEBHELPERS_EGG=${PYWEBHELPERS_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

post-install:
	${FIND} ${PYTHON_SITELIBDIR}/${PYWEBHELPERS_EGG} \
		-type d -exec ${CHMOD} 755 {} +
	${FIND} ${PYTHON_SITELIBDIR}/${PYWEBHELPERS_EGG} \
		-type f -exec ${CHMOD} ${SHAREMODE} {} +

.include <bsd.port.mk>
