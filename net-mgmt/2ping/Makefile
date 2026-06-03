PORTNAME=	2ping
PORTVERSION=	4.6.1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	https://www.finnie.org/software/2ping/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bi-directional ping utility
WWW=		https://www.finnie.org/software/2ping/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist noflavors pep517

NO_ARCH=	yes

.include <bsd.port.mk>
