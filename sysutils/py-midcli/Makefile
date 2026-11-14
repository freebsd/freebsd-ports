PORTNAME=	midcli
DISTVERSIONPREFIX=	TS-
DISTVERSION=	25.10.8
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	longros@FreeBSD.org
COMMENT=	TrueNAS command line interface
WWW=		https://github.com/truenas/midcli

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/debian/copyright

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prompt-toolkit>0:devel/py-prompt-toolkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.0.0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}truenas-api-client>0:sysutils/py-truenas-api-client@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	truenas
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|name='midcli',|&version='${DISTVERSION}',|" \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
