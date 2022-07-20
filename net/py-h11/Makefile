PORTNAME=	h11
PORTVERSION=	0.13.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pure-Python, bring-your-own-I/O implementation of HTTP/1.1

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox -e ${PY_FLAVOR} --parallel 0

.include <bsd.port.mk>
