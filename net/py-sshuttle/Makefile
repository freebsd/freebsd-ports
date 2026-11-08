PORTNAME=	sshuttle
DISTVERSION=	2.0.0
CATEGORIES=	net python net-vpn
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Full-featured VPN over an SSH tunnel
WWW=		https://github.com/sshuttle/sshuttle

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
