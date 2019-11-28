# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wsproto
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sans-IO WebSocket protocol implementation

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h11>=0.8.1:net/py-h11@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3700
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>0:devel/py-dataclasses@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
