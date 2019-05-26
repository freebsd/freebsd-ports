# $FreeBSD$

PORTNAME=	rmsd
DISTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculate root-mean-square deviation (RMSD) between coordinate sets

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.mk>
