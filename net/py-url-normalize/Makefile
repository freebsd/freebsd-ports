PORTNAME=	url-normalize
PORTVERSION=	2.2.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	url_normalize-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	URL normalization for Python
WWW=		https://github.com/niksite/url-normalize

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=42:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}idna>=3.3:dns/py-idna@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
