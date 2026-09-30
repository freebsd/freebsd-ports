PORTNAME=	web_py
PORTVERSION=	0.76
CATEGORIES=	www python
MASTER_SITES=	http://webpy.org/static/ \
		PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	web_py-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Web Framework For Python
WWW=		https://webpy.org/

LICENSE=	PD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
