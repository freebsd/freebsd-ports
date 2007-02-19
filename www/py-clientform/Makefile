# New ports collection makefile for:	py-clientform
# Date created:				25 Jun 2004
# Whom:					"Choe, Cheng-Dae" <whitekid@netian.com>
#
# $FreeBSD$
#

PORTNAME=	clientform
PORTVERSION=	0.2.6
CATEGORIES=	www python
MASTER_SITES=	http://wwwsearch.sourceforge.net/ClientForm/src/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ClientForm-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Client-side HTTP Form for Python

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYCLIENTFORM_EGG=	ClientForm-${PORTVERSION}-py${PYTHON_VER}.egg

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PYCLIENTFORM_EGG=${PYCLIENTFORM_EGG} \
		PYCLIENTFORM_EGG_VER="ClientForm==${PORTVERSION}"

.include <bsd.port.mk>
