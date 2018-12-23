# $FreeBSD$

PORTNAME=	compreffor
PORTVERSION=	0.4.6
CATEGORIES=	x11-fonts python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	CFF subroutinizer for fontTools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=3.1:print/py-fonttools@${PY_FLAVOR}

USES=		compiler:c++11-lang python zip
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
