PORTNAME=	pyteomics
PORTVERSION=	4.4.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python modules for proteomics data analysis

LICENSE=	APACHE20

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DF GRAPHICS TDA UNIMOD XML
OPTIONS_DEFAULT=DF GRAPHICS TDA UNIMOD XML
DF_DESC=	DataFrame support
GRAPHICS_DESC=	Graphics support
TDA_DESC=	Target-decoy approach support
UNIMOD_DESC=	Unimod database support
XML_DESC=	XML support

DF_RUN_DEPENDS=		${PY_PANDAS}
GRAPHICS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}
TDA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}
UNIMOD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sqlalchemy13>=0:databases/py-sqlalchemy13@${PY_FLAVOR}
XML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

.include <bsd.port.mk>
