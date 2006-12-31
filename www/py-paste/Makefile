# New ports collection makefile for:	py-paste
# Date created:		14 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	Paste
PORTVERSION=	1.0
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/P/Paste/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dryice@dryice.name
COMMENT=	Tools for using a Web Server Gateway Interface stack

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
PASTEVER?=	${PORTVERSION}
PYTHONVER?=	${_PYTHON_VERSION}
PLIST_SUB=	PASTEVER=${PASTEVER} \
		PYTHONVER=${PYTHONVER}

SUB_FILES+=	pkg-deinstall pkg-install
SUB_LIST+=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EGG="${PORTNAME}==${PORTVERSION}"

PYPASTE_EGG=	${PORTNAME}-${PORTVERSION}-${PYTHON_VERSION:S/^python//}.egg

.include <bsd.port.mk>
