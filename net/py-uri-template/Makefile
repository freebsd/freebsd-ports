PORTNAME=	uri-template
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uri_template-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RFC 6570 URI Template Processor
WWW=		https://github.com/plinss/uri_template

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
