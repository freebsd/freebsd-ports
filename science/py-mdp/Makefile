# Ports collection makefile for:	mdp
# Date created:				September 9, 2008
# Whom:					Li-Lun Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	mdp
PORTVERSION=	2.4
CATEGORIES=	science python
MASTER_SITES=	SF/${PORTNAME}-toolkit/${PORTNAME}-toolkit/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	llwang@infor.org
COMMENT=	Modular toolkit for Data Processing

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_SITELIBDIR}/scipy/__init__.py:${PORTSDIR}/science/py-scipy \
		${PYTHON_SITELIBDIR}/symeig/__init__.py:${PORTSDIR}/math/py-symeig

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g:U}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-${PYTHON_VERSION:S/thon//}.egg-info

.include <bsd.port.mk>
