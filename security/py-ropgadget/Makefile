# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	ropgadget
PORTVERSION=	6.8
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ROPGadget-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to search gadgets to facilitate ROP exploitation

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>=4.0.1:devel/py-capstone@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
