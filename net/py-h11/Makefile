PORTNAME=	h11
PORTVERSION=	0.14.0
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Pure-Python, bring-your-own-I/O implementation of HTTP/1.1
WWW=		https://pypi.org/project/h11/

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tox>0:devel/py-tox@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${LOCALBASE}/bin/tox -e ${PY_FLAVOR} --parallel 0

.include <bsd.port.mk>
