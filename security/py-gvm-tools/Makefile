PORTNAME=	gvm-tools
DISTVERSION=	25.4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Greenbone Vulnerability Management Tools
WWW=		https://github.com/greenbone/gvm-tools

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-gvm>=0:security/py-python-gvm@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/gvmtools/
	${MV} ${WRKSRC}/scripts ${WRKSRC}/gvmtools/

post-patch:
	${REINPLACE_CMD} '31,32d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
