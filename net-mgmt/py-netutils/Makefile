PORTNAME=	netutils
DISTVERSION=	1.18.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Common helper functions useful in network automation
WWW=		https://github.com/networktocode/netutils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0.0<3.0.0:devel/py-poetry-core@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

# There are another two options, "napalm" + "legacycrypt", in "pyproject.toml"
# and are deliberately not added for the time being.  The first one  would lead
# to a circular dependency and the second one is required for Python 3.13+ (not
# in ports tree, yet) which no longer has the deprecated "crypt" module.
OPTIONS_DEFINE=		JINJA2 JSONSCHEMA
OPTIONS_DEFAULT=	JINJA2 JSONSCHEMA

JINJA2_DESC=		Jinja2-aware config sanitizer support
JSONSCHEMA_DESC=	ACL check support

JINJA2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6<4.0.0:devel/py-Jinja2@${PY_FLAVOR}
JSONSCHEMA_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=4.17.3<5.0.0:devel/py-jsonschema@${PY_FLAVOR}

.include <bsd.port.mk>
