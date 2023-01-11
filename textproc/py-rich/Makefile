PORTNAME=	rich
PORTVERSION=	13.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Rich text and beautiful formatting in the terminal
WWW=		https://github.com/willmcgugan/rich

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}CommonMark>=0.9.0:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.6.0:textproc/py-pygments@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30900
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
