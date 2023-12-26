PORTNAME=	python-mpv
DISTVERSION=	1.0.5
CATEGORIES=	multimedia python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lexi.freebsd@le-fay.org
COMMENT=	Python interface to the mpv media player
WWW=		https://pypi.org/project/python-mpv/

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	dual

BUILD_DEPENDS=  ${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	mpv>0:multimedia/mpv

USES=		python
USE_PYTHON=	pep517 autoplist

.include <bsd.port.mk>
