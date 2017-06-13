# $FreeBSD$

PORTNAME=	vcrpy
PORTVERSION=	1.11.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Automatically mock your HTTP interactions to simplify and speed up testing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}wrapt>0:devel/py-wrapt \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}contextlib2>0:devel/py-contextlib2
.endif

.include <bsd.port.post.mk>
