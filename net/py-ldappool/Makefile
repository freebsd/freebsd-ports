PORTNAME=	ldappool
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Simple connector pool for py-ldap
WWW=		https://pypi.org/project/ldappool/

LICENSE=	MPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}prettytable0>=0.7.2<0.8:devel/py-prettytable0@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>=3.0.0:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
