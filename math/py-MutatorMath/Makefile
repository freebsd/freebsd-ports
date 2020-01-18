# $FreeBSD$

PORTNAME=	MutatorMath
PORTVERSION=	2.1.2
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	Piecewise linear interpolation in multiple dimensions

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defcon>=0.3.5:x11-fonts/py-defcon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fontMath>=0.4.8:x11-fonts/py-fontMath@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools3>=3.32.0:print/py-fonttools3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.32.0:print/py-fonttools@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
