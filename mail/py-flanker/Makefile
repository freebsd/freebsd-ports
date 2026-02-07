PORTNAME=	flanker
PORTVERSION=	0.9.11
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Email address and MIME parsing library
WWW=		https://github.com/mailgun/flanker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=1.0.1,1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=3.10:devel/py-ply@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=0.1.20110315:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tld>=0:dns/py-tld@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.8:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CCHARDET
CCHARDET_DESC=	Character encoding detection via cchardet

CCHARDET_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cchardet>=0.3.5:textproc/py-cchardet@${PY_FLAVOR}

.include <bsd.port.mk>
