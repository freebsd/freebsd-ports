# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	wordcloud
DISTVERSION=	1.8.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Little word cloud generator in Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}
RUN_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	amueller

USES=		python:3.7+
USE_PYTHON=	distutils

PLIST_SUB+=	VER=${PORTVERSION}
TEST_TARGET=	test

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
