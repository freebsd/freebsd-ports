# $FreeBSD$

PORTNAME=	orange3-datafusion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11-7
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g69aa51c
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data fusion add-on for Orange3

LICENSE=	GPLv3

RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYTHON_PKGNAMEPREFIX}scikit-fusion>0:misc/py-scikit-fusion@${PY_FLAVOR}

USES=		python:3.4+
USE_GITHUB=	yes
GH_ACCOUNT=	biolab
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
