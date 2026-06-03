PORTNAME=	icoextract
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	GH
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Extract icons from Windows EXE and DLL files

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pefile>0:devel/py-pefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	jlu5

.include <bsd.port.mk>
