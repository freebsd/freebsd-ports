# $FreeBSD$

PORTNAME=	cowrie
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	security python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cowrie SSH/Telnet honeypot

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0.9.1:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=14.0.0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=17.1.0:devel/py-twisted@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	bin/cowrie
USE_GITHUB=	yes
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
