# $FreeBSD$

PORTNAME=	rmsd
DISTVERSION=	1.3.2
CATEGORIES=	science
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Calculate root-mean-square deviation (RMSD) between coordinate sets

LICENSE=	APACHE20
xLICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist concurrent

.include <bsd.port.mk>
