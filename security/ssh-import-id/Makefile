PORTNAME=	ssh-import-id
DISTVERSION=	5.11
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	p.mousavizadeh@protonmail.com
COMMENT=	Authorize SSH public keys from trusted online identities
WWW=		https://git.launchpad.net/ssh-import-id

LICENSE=	GPLv3
# LICENSE_FILE=Not shipped in PyPI sdist
# https://bugs.launchpad.net/ssh-import-id/+bug/1992842

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR}

USES=		python
USE_PYTHON=	concurrent autoplist distutils

.include <bsd.port.mk>
