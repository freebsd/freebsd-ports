# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.34.2
CATEGORIES=	print python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python zip
USE_PYTHON=	autoplist concurrent distutils

MAKE_ENV=	FONTTOOLS_MANPATH="man"
NO_ARCH=	yes

.include <bsd.port.mk>
