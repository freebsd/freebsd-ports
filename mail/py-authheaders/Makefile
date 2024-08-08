PORTNAME=	authheaders
DISTVERSION=	0.16.3
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Generate email authentication headers
WWW=		https://github.com/ValiMail/authentication-headers

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/MPL-2.0

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dkimpy>=0.7.1:mail/py-dkimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>=1.2.0:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>0:dns/py-publicsuffix2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
NO_BUILD=	yes

.include <bsd.port.mk>
