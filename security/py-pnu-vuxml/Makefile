PORTNAME=	pnu-vuxml
DISTVERSION=	1.2.0
CATEGORIES=	security ports-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hubert.tournier@gmail.com
COMMENT=	FreeBSD VuXML library and query tool
WWW=		https://github.com/HubTou/vuxml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>0:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pnu-libpnu>=1.3.0:devel/py-pnu-libpnu@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist flavors pep517

SHEBANG_FILES=	src/vuxml/*.py

.include <bsd.port.mk>
