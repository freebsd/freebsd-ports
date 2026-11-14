PORTNAME=	rolo
PORTVERSION=	0.8.9
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python framework for building HTTP-based server applications
WWW=		https://rolo.localstack.cloud/ \
		https://github.com/localstack/rolo

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.20:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=3.0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=1.0.0:net/py-wsproto@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	HYPERCORN TWISTED
HYPERCORN_DESC=	Serve Rolo components through Hypercorn
TWISTED_DESC=	Serve Rolo components through Twisted

HYPERCORN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypercorn>=0:www/py-hypercorn@${PY_FLAVOR}
TWISTED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=24:devel/py-twisted@${PY_FLAVOR}

.include <bsd.port.mk>
