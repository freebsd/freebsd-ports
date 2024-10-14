PORTNAME=	pydicom
PORTVERSION=	3.0.1
DISTVERSIONPREFIX=v
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Read, modify, and write DICOM files with Python code
WWW=		https://github.com/pydicom/pydicom

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
USE_PYTHON=	autoplist pep517
NO_ARCH=	yes

.include <bsd.port.mk>
