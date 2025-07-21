PORTNAME=	pynzb
PORTVERSION=	0.1.0
PORTREVISION=	4
CATEGORIES=	news python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unified API for parsing NZB files
WWW=		https://pypi.org/project/pynzb/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	LXML
LXML_DESC=	Add support for py-lxml5
LXML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=2.2.1:devel/py-lxml5@${PY_FLAVOR}

.include <bsd.port.mk>
