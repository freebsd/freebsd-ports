# New ports collection makefile for:	py-pastescript
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	PasteScript
PORTVERSION=	1.3.3
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/P/PasteScript/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	A pluggable command-line frontend

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}
RUN_DEPENDS+=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/${PYFLUP_EGG}/flup/__init__.py:${PORTSDIR}/www/py-flup \
		${PYTHON_SITELIBDIR}/${PYPASTE_EGG}/paste/__init__.py:${PORTSDIR}/www/py-paste \
		${PYTHON_SITELIBDIR}/${PYPASTEDEPLOY_EGG}/paste/deploy/__init__.py:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_SITELIBDIR}/${PYWSGIUTILS_EGG}:${PORTSDIR}/devel/py-wsgiutils \
		${PYTHON_SITELIBDIR}/twisted/plugins/twisted_web2.py:${PORTSDIR}/www/py-twistedWeb2

# due to devel/py-cheetah
NO_PACKAGE=	no, not yet

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

PLIST_SUB=	PYPASTESCRIPT_EGG=${PYPASTESCRIPT_EGG}

PYPASTESCRIPT_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.pre.mk>

PYFLUP_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-flup/Makefile -V PYFLUP_EGG
PYPASTE_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-paste/Makefile -V PYPASTE_EGG
PYPASTEDEPLOY_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-pastedeploy/Makefile -V PYPASTEDEPLOY_EGG
PYWSGIUTILS_EGG!=	${MAKE} -f ${PORTSDIR}/devel/py-wsgiutils/Makefile -V PYWSGIUTILS_EGG

.include <bsd.port.post.mk>
