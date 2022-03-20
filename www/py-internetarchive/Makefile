PORTNAME=	internetarchive
DISTVERSION=	3.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface to archive.org

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docopt>=0.6.0,<0.7.0:devel/py-docopt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>=0.4:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.25.0,<3.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>=0.4.0:devel/py-schema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.13.0,<2.0.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.26.0:net/py-urllib3@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
