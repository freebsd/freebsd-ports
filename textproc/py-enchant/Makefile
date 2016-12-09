# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	enchant
PORTVERSION=	1.6.8
CATEGORIES=	textproc devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Spellchecking library for Python based on the Enchant library

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libenchant.so:textproc/enchant

USES=		python
USE_PYTHON=	distutils
USE_WX=		3.0+
WX_COMPS=	python:run

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
