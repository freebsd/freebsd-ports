PORTNAME=	wsproto
DISTVERSION=	1.3.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Sans-IO WebSocket protocol implementation
WWW=		https://pypi.org/project/wsproto/ \
		https://github.com/python-hyper/wsproto/

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h11>=0.16.0:net/py-h11@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} '/license-files/d; s|77|63|g; s|^license = "MIT"|license = { text = "MIT" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
