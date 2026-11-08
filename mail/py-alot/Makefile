PORTNAME=	alot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mail@dbalan.in
COMMENT=	Terminal MUA using Notmuch mail
WWW=		https://github.com/pazz/alot

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>4.7.0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gpg>=2.0.0:security/py-gpg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notmuch2>=0.34.2:mail/py-notmuch2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>0:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.4.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=1.3.0:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwidtrees>=1.0.3:devel/py-urwidtrees@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	pazz

USE_PYTHON=	autoplist concurrent pep517
MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}standard-mailcap>0:mail/py-standard-mailcap@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
