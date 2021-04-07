PORTNAME=	alot
DISTVERSION=	0.9
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@dbalan.in
COMMENT=	Terminal MUA using Notmuch mail

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notmuch>=0.27:mail/py-notmuch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpgme>0:security/py-gpgme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>4.7.0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>0:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.4.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwidtrees>1.0:devel/py-urwidtrees@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	pazz

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
