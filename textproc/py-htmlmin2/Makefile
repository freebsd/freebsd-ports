PORTNAME=	htmlmin2
PORTVERSION=	0.1.13
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	HTML Minifier
WWW=		https://htmlmin.readthedocs.io/en/latest/ \
		https://github.com/wilhelmer/htmlmin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wilhelmer
GH_PROJECT=	htmlmin

.include <bsd.port.mk>
