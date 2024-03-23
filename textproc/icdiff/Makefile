PORTNAME=	icdiff
PORTVERSION=	2.0.7
PORTREVISION=	1
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Improved colored diff
WWW=		https://www.jefftk.com/icdiff \
		https://github.com/jeffkaufman/icdiff

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

USE_GITHUB=	yes
GH_ACCOUNT=	jeffkaufman

NO_ARCH=	yes

.include <bsd.port.mk>
