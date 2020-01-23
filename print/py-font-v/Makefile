# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	font-v
PORTVERSION=	0.7.1
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Font version reporting and modification tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}GitPython>=0:devel/py-gitpython@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools3>=0:print/py-fonttools3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools>=0:print/py-fonttools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
