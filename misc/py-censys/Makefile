PORTNAME=	censys
DISTVERSION=	2.2.13
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight API wrapper for Censys APIs (censys.io)
WWW=		https://censys.io/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argcomplete>=2.0.0:devel/py-argcomplete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}backoff>=2.0.0:devel/py-backoff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.29.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=10.16.2:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
