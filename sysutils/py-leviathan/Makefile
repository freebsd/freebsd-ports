PORTNAME=	leviathan
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Application to control and monitor NZXT (Asetek) liquid coolers

LICENSE=	GPLv2
#LICENSE_FILE=	Not packaged with PyPI sdist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
