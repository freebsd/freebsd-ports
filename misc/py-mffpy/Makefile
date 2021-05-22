PORTNAME=	mffpy
DISTVERSION=	0.6.3
CATEGORIES=	misc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reader and writer for Philips' MFF file format

LICENSE=	APACHE20

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}deprecated>=1.2.12:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2019.2:devel/py-pytz@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python:3.6+
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
