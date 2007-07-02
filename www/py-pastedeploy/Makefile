# New ports collection makefile for:	py-pastedeploy
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	PasteDeploy
PORTVERSION=	1.3.1
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/P/PasteDeploy/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	dryice
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@FreeBSD.org
COMMENT=	Load, configure, and compose WSGI applications and servers

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_SITELIBDIR}/${PYPASTE_EGG}/paste/__init__.py:${PORTSDIR}/www/py-paste
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

PLIST_SUB=	PYPASTEDEPLOY_EGG=${PYPASTEDEPLOY_EGG}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

PYPASTEDEPLOY_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VERSION:S/^python//}.egg

.include <bsd.port.pre.mk>

PYPASTE_EGG!=	${MAKE} -f ${PORTSDIR}/www/py-paste/Makefile -V PYPASTE_EGG

.include <bsd.port.post.mk>
