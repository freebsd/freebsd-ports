PORTNAME=	chameleon
PORTVERSION=	4.4.0
CATEGORIES=	textproc www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Chameleon-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Fast HTML/XML Template Compiler
WWW=		https://chameleon.readthedocs.io/en/latest/ \
		https://github.com/malthe/chameleon

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=0:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.if ${PYTHON_REL} < 31000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
