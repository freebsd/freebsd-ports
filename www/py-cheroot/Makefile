# Created by: Keith Gaughan <k@stereochro.me>
# $FreeBSD$

PORTNAME=	cheroot
DISTVERSION=	6.0.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	k@stereochro.me
COMMENT=	Highly-optimized, pure-python HTTP server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=1.15.0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}more-itertools>=2.6:devel/py-more-itertools@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}more-itertools5>=2.6:devel/py-more-itertools5@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
