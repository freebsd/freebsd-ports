PORTNAME=	rfc3987-syntax
PORTVERSION=	1.1.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	rfc3987_syntax-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper functions to syntactically validate strings according to RFC 3987
WWW=		https://github.com/willynilly/rfc3987-syntax

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark>=1.2.2:devel/py-lark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
