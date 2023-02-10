PORTNAME=	PySCIPOpt
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface and modeling environment for SCIP
WWW=		https://github.com/SCIP-Interfaces/PySCIPOpt

LICENSE=	MIT

LIB_DEPENDS=	libscip.so:math/SCIP

USES=		localbase python:3.6+
USE_PYTHON=	distutils cython autoplist

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscipopt/scip*.so

.include <bsd.port.mk>
