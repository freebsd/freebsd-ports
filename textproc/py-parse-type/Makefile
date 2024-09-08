PORTNAME=	parse-type
PORTVERSION=	0.6.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	parse_type-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simplify to build parse types based on the parse module
WWW=		https://github.com/jenisys/parse_type

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}parse>=1.18.0:textproc/py-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.15:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
