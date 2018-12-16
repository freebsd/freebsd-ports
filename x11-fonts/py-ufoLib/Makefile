# $FreeBSD$

PORTNAME=	ufoLib
PORTVERSION=	2.3.2
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Low-level Unified Font Object (UFO) reader and writer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.1.2:print/py-fonttools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=4.0:devel/py-lxml@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}singledispatch>=3.4.0.3:devel/py-singledispatch@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
