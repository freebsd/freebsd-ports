PORTNAME=	ospd-openvas
DISTVERSION=	21.4.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
#MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Scanner wrapper for OSP (Open Scanner Protocol)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		openvas:security/openvas

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python:3.8+
USE_PYTHON=	distutils

NO_ARCH=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME:S/-/_/}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-extract:
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.mk>
