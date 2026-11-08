PORTNAME=	fingerprints
DISTVERSION=	1.3.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Easy comparing and cross-referencing of companies and people
WWW=		https://github.com/opensanctions/fingerprints

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}normality>=3.0.1<4.0.0:textproc/py-normality@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	alephdata
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
