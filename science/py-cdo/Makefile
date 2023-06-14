PORTNAME=	cdo
PORTVERSION=	1.6.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding to CDO (Climate Data Operators)
WWW=		https://code.mpimet.mpg.de/projects/cdo/wiki/Cdo%7Brbpy%7D

LICENSE=	GPLv2

RUN_DEPENDS=	cdo:science/cdo \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
