# $FreeBSD$

PORTNAME=	pdftotext
PORTVERSION=	2.1.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Simple PDF text extraction

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpoppler.so:graphics/poppler

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
