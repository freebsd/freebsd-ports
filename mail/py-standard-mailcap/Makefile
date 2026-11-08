PORTNAME=	standard-mailcap
PORTVERSION=	3.13.0
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	standard_mailcap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Standard library mailcap redistribution
WWW=		https://github.com/youknowone/python-deadlib/tree/main/mailcap \
		https://github.com/youknowone/python-deadlib

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
