# Created by: Stefan Esser <se@FreeBSD.org>

PORTNAME=	utidylib
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	uTidylib-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to tidy-lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtidy5.so:www/tidy-html5

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
