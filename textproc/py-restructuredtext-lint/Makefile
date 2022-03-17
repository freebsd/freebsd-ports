PORTNAME=	restructuredtext-lint
DISTVERSION=	1.4.0
CATEGORIES=	textproc devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	reStructuredText linter

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docutils>=0.11,1<1.0,1:textproc/py-docutils@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	twolfson
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
