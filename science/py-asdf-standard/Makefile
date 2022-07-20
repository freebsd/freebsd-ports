PORTNAME=	asdf-standard
PORTVERSION=	1.0.2
CATEGORIES=	science python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	asdf_standard-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ASDF Standard schemas

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python:3.8+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-resources>=3:devel/py-importlib-resources@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
