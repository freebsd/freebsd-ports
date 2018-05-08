# $FreeBSD$

PORTNAME=	PySCIPOpt
DISTVERSION=	1.4.6
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface and modeling environment for SCIP

LICENSE=	MIT

LIB_DEPENDS=	libscip.so:math/SCIP

USES=		localbase python
USE_PYTHON=	distutils cython autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscipopt/scip.so

.include <bsd.port.mk>
