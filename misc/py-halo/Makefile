PORTNAME=	halo
DISTVERSION=	0.0.31
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Beautiful terminal spinners in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>=0.3.9:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}log_symbols>=0.0.14:misc/py-log_symbols@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spinners>=0.0.24:misc/py-spinners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=1.1.0:devel/py-termcolor@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
