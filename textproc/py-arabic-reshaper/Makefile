PORTNAME=	arabic-reshaper
PORTVERSION=	3.0.0
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	arabic_reshaper-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reconstruct Arabic sentences to be used in applications that do not support Arabic
WWW=		https://github.com/mpcabd/python-arabic-reshaper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
