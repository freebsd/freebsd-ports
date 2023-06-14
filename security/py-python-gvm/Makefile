PORTNAME=	python-gvm
DISTVERSION=	23.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The Greenbone Vulnerability Management Python API library
WWW=		https://github.com/greenbone/python-gvm

LICENSE=	GPLv3+

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry2setup>0:devel/py-poetry2setup@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/gvm/

post-patch:
	${REINPLACE_CMD} -i "" -e 's|/run/gvmd/|/var/run/gvmd/|g' \
		${WRKSRC}/gvm/connections.py
	${REINPLACE_CMD} '31d' ${WRKSRC}/pyproject.toml

pre-configure:
	@cd ${WRKSRC} && poetry2setup > ${WRKSRC}/setup.py

.include <bsd.port.mk>
