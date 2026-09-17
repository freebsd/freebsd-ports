PORTNAME=	pygtrie
PORTVERSION=	2.6.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pygtrie-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pure Python trie data structure implementation
WWW=		https://github.com/mina86/pygtrie

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} test.py

# tests as of 2.6.2: Ran 461 tests in 0.590s

.include <bsd.port.mk>
