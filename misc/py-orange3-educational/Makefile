# $FreeBSD$

PORTNAME=	orange3-educational
DISTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Orange add-on: widgets for machine learning and data mining

LICENSE=	CC-BY-3.0
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	orange3>0:misc/orange3

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
