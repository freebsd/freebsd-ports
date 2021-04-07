PORTNAME=	authheaders
DISTVERSION=	0.13.0
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Generate email authentication headers

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/MPL-2.0

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dkimpy>=0.7.1:mail/py-dkimpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authres>=1.0.1:mail/py-authres@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>0:dns/py-publicsuffix2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_BUILD=	yes
NO_ARCH=	yes

.include <bsd.port.mk>
