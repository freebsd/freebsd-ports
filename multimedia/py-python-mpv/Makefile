PORTNAME=	python-mpv
PORTVERSION=	1.0.7
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_mpv-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface to the mpv media player
WWW=		https://github.com/jaseg/python-mpv

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	dual
LICENSE_GPLv2+ =	${WRKSRC}/LICENSE.GPL
LICENSE_LGPL21+ =	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libmpv.so:multimedia/mpv

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
