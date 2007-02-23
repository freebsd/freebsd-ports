# ex:ts=8
# Ports collection makefile for:	py-mechanize
# Date created:			Apr 29, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mechanize
PORTVERSION=	0.1.6.b
CATEGORIES=	www python
MASTER_SITES=	http://wwwsearch.sourceforge.net/mechanize/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stateful programmatic web browsing in Python

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_SITELIBDIR}/ClientCookie/__init__.py:${PORTSDIR}/devel/py-clientcookie \
		${PYTHON_SITELIBDIR}/${PYCLIENTFORM_EGG}:${PORTSDIR}/www/py-clientform \
		${PYTHON_SITELIBDIR}/pullparser.py:${PORTSDIR}/www/py-pullparser
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PYMECHANIZE_EGG}

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYMECHANIZE_EGG=${PYMECHANIZE_EGG} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PYMECHANIZE_EGG=	${DISTNAME}-py${PYTHON_VER}.egg	

.include <bsd.port.pre.mk>

PYCLIENTFORM_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-clientform/Makefile -V PYCLIENTFORM_EGG

.include <bsd.port.post.mk>
