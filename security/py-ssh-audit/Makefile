PORTNAME=	ssh-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	SSH server auditing
WWW=		https://github.com/jtesta/ssh-audit

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	jtesta
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
