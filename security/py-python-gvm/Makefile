PORTNAME=	python-gvm
DISTVERSION=	26.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Greenbone Vulnerability Management Python API library
WWW=		https://github.com/greenbone/python-gvm

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/gvm/

post-patch:
	${REINPLACE_CMD} -i "" -e 's|/run/gvmd/|/var/run/gvmd/|g' \
		${WRKSRC}/gvm/connections/_unix.py
	${REINPLACE_CMD} -e 's|, { include = "tests", format = "sdist" }||g' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
