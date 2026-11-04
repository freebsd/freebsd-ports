PORTNAME=	mkdocs-simple-hooks
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samir@noir.im
COMMENT=	MkDocs plugin to define hooks
WWW=		https://github.com/aklajnert/mkdocs-simple-hooks

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Deprecated upstream, mkdocs 1.4+ has hooks built in
EXPIRATION_DATE=2026-11-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs>=1.2.0:textproc/py-mkdocs@${PY_FLAVOR}

TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	aklajnert
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest tests.py

.include <bsd.port.mk>
