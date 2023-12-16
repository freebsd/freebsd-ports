PORTNAME=	wagtail-transfer
PORTVERSION=	0.9.3
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Content transfer for Wagtail
WWW=		https://github.com/wagtail/wagtail-transfer

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wagtail>=4.1:www/py-wagtail@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	wagtail

.include <bsd.port.mk>
