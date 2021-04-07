PORTNAME=	terminado
PORTVERSION=	0.8.3
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Terminals served to term.js using Tornado websockets

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ptyprocess>0:sysutils/py-ptyprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4:www/py-tornado@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
