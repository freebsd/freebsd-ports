PORTNAME=	pyteomics
PORTVERSION=	4.7.5
PORTREVISION=	2
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python modules for proteomics data analysis
WWW=		https://pyteomics.readthedocs.io/en/latest/ \
		https://github.com/levitsky/pyteomics

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DF GRAPHICS TDA UNIMOD XML
OPTIONS_DEFAULT=DF GRAPHICS TDA UNIMOD XML
DF_DESC=	DataFrame support
GRAPHICS_DESC=	Graphics support
TDA_DESC=	Target-decoy approach support
UNIMOD_DESC=	Unimod database support
XML_DESC=	XML support

DF_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pandas>=0.17,1:math/py-pandas@${PY_FLAVOR}
GRAPHICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
TDA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
UNIMOD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=0:databases/py-sqlalchemy14@${PY_FLAVOR}
XML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
