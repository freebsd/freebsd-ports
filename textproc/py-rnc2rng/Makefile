# $FreeBSD$

PORTNAME=	rnc2rng
DISTVERSION=	2.6.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	RELAX NG Compact to regular syntax conversion library

LICENSE=	PD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}rply>0:devel/py-rply@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
