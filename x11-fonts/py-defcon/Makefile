# $FreeBSD$

PORTNAME=	defcon
PORTVERSION=	0.6.0
PORTREVISION=	3
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Set of flexible objects for representing UFO data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		python zip
USE_PYTHON=	autoplist distutils
USE_LOCALE=	en_US.UTF-8

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools3>=3.31.0:print/py-fonttools3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.31.0:print/py-fonttools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
