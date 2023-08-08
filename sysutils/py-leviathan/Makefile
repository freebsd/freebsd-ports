PORTNAME=	leviathan
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application to control and monitor NZXT (Asetek) liquid coolers
WWW=		https://github.com/jaksi/leviathan/tree/0.1.1

LICENSE=	GPLv2
#LICENSE_FILE=	Not packaged with PyPI sdist

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
