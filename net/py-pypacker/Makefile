PORTNAME=	pypacker
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Packet manipulation library for Python
WWW=		https://gitlab.com/mike01/pypacker

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

USE_GITLAB=	yes
GL_ACCOUNT=	mike01

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|5.9|${DISTVERSION}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
