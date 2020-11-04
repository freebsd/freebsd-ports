# $FreeBSD$

PORTNAME=	soupsieve
PORTVERSION=	2.0.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	CSS4 selector implementation for BeautifulSoup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html5lib>0:www/py-html5lib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>4:www/py-beautifulsoup@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.functools_lru_cache>0:devel/py-backports.functools_lru_cache@${PY_FLAVOR}
.endif

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.post.mk>
