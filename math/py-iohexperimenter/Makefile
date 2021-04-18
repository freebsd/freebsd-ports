# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	iohexperimenter
PORTVERSION=	0.2.9
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	IOHexperimenter-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Experimenter for Iterative Optimization Heuristic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++14-lang dos2unix python:3.6+
USE_PYTHON=	autoplist concurrent distutils

USE_CXXSTD=	c++14
WRKSRC=		${WRKDIR}/IOHexperimenter-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/IOHexperimenter/_IOHprofiler*.so

.include <bsd.port.mk>
