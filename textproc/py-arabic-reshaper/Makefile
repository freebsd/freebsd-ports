# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	arabic-reshaper
PORTVERSION=	2.1.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	arabic_reshaper-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Reconstruct Arabic sentences to be used in applications that do not support Arabic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
