PORTNAME=	wordcloud
DISTVERSION=	1.9.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Little word cloud generator in Python
WWW=		https://amueller.github.io/word_cloud/

LICENSE=	MIT

BUILD_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}
RUN_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}

#USE_GITHUB=	yes
#GH_ACCOUNT=	amueller

USES=		python
USE_PYTHON=	distutils

PLIST_SUB+=	VER=${PORTVERSION}

.if !defined(WITH_DEBUG)
LDFLAGS+=	-s
.endif

.include <bsd.port.mk>
