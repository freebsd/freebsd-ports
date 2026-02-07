PORTNAME=	alot
DISTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@dbalan.in
COMMENT=	Terminal MUA using Notmuch mail
WWW=		https://github.com/pazz/alot

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}notmuch>=0.27:mail/py-notmuch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>4.7.0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>0:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.4.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwidtrees>1.0:devel/py-urwidtrees@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>0:security/py-service-identity@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pazz

USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
