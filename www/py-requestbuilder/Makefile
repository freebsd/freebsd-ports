# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	requestbuilder
PORTVERSION=	0.4.0
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Command line-driven HTTP request builder

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USES=		python:-2.7
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
