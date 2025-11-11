PORTNAME=	cowrie
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
PORTREVISION=	4
CATEGORIES=	security python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cowrie SSH/Telnet honeypot
WWW=		https://www.cowrie.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR}
RUN_DEPENDS=	bash:shells/bash \
		${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}incremental>0:devel/py-incremental@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tftpy>0:ftp/py-tftpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>0:devel/py-twisted@${PY_FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	bin/cowrie
USE_GITHUB=	yes
USE_PYTHON=	autoplist cryptography noflavors distutils

CONFLICTS_INSTALL=	py*-asciinema # bin/asciinema

NO_ARCH=	yes

.include <bsd.port.mk>
