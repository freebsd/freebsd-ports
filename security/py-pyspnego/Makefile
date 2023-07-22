PORTNAME=	pyspnego
PORTVERSION=	0.9.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Windows Negotiate Authentication Client and Server
WWW=		https://github.com/jborean93/pyspnego

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python pycryptography:run
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	KERBEROS YAML
KERBEROS_DESC=	Kerberos authentication support
YAML_DESC=	YAML output support

KERBEROS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gssapi>=1.6.0:security/py-gssapi@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}krb5>=0.3.0:security/py-krb5@${PY_FLAVOR}
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0:devel/py-ruamel.yaml@${PY_FLAVOR}

.include <bsd.port.mk>
