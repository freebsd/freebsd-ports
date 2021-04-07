PORTNAME=	pywinrm
PORTVERSION=	0.4.1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Python library for Windows Remote Management (WinRM)

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xmltodict>0:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.9.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests_ntlm>=0.3.0:www/py-requests_ntlm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-kerberos>=0.10.0:security/py-requests-kerberos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-credssp>=0.0.1:security/py-requests-credssp@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

# Actually 2.6-2.7,3.3-3.6
USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v winrm/tests/

.include <bsd.port.mk>
