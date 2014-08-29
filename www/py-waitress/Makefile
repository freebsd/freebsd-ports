# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	waitress
PORTVERSION=	0.8.9
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Python WSGI server

LICENSE=	ZPL21

USES=	python
USE_PYTHON=	distutils autoplist

pre-patch:
	@${CP} ${FILESDIR}/MANIFEST.in ${WRKSRC}

.include <bsd.port.mk>
