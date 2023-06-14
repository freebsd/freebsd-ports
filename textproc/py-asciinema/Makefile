PORTNAME=	asciinema
PORTVERSION=	2.2.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tool for recording and sharing terminal sessions
WWW=		https://asciinema.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		python
USE_PYTHON=	autoplist pep517

CONFLICTS_INSTALL=	cowrie # bin/asciinema

NO_ARCH=	yes

.include <bsd.port.mk>
