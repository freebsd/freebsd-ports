PORTNAME=	markups
PORTVERSION=	4.0.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Markups-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper around various text markup languages
WWW=		https://github.com/retext-project/pymarkups

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-markdown-math>=0:textproc/py-python-markdown-math@${PY_FLAVOR}

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}/

.include <bsd.port.mk>
