# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	utidylib
PORTVERSION=	0.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uTidylib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to tidy-lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtidy.so.5:www/tidy-html5
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
