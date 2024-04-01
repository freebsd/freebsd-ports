PORTNAME=	pnu-portstreelint
DISTVERSION=	1.3.0
CATEGORIES=	ports-mgmt security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	hubert.tournier@gmail.com
COMMENT=	FreeBSD ports tree lint
WWW=		https://github.com/HubTou/portstreelint

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pnu-libpnu>=1.3.0:devel/py-pnu-libpnu@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pnu-vuxml>=1.2.1:security/py-pnu-vuxml@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist flavors pep517

SHEBANG_FILES=	src/portstreelint/*.py

.include <bsd.port.mk>
