# Created by: gnn
# $FreeBSD$

PORTNAME=	pdb
PORTVERSION=	0.1
CATEGORIES=	net
MASTER_SITES=	SF/pktdbg/pktdbg/${PORTVERSION}%20Beta
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Packet Debugger

DEPRECATED=	Depends on expired net/py-pcs
EXPIRATION_DATE=2019-02-01

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pcs/__init__.py:net/py-pcs@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils pythonprefix

.include <bsd.port.mk>
