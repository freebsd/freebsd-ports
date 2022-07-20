PORTNAME=	crudini
PORTVERSION=	0.9.3
CATEGORIES=	misc python
#MASTER_SITES=	CHEESESHOP
MASTER_SITES=	https://github.com/pixelb/crudini/releases/download/${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility for manipulating ini files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}iniparse>=0.3.2:devel/py-iniparse@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
