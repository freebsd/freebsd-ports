PORTNAME=	pysmartdl
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pySmartDL-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Smart download manager for Python
WWW=		https://github.com/iTaybb/pySmartDL

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
