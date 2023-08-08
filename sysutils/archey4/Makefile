PORTNAME=	archey4
PORTVERSION=	4.14.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Simple system information tool written in Python
WWW=		https://github.com/HorlogeSkynet/archey4

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>=1.3:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10:net/py-netifaces@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

do-test:
	@${PYTHON_CMD} -m ${PORTNAME:C/[0-9]//}

.include <bsd.port.mk>
