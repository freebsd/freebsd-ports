PORTNAME=	pyzor
PORTVERSION=	1.1.2
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Collaborative, networked system to detect and block spam
WWW=		https://github.com/SpamExperts/pyzor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdbm>=0:databases/py-gdbm@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	SpamExperts
GH_TAGNAME=	release-1-1-2
USE_PYTHON=	pep517 autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
