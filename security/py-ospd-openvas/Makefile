PORTNAME=	ospd-openvas
DISTVERSION=	22.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	security python
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Scanner wrapper for OSP (Open Scanner Protocol)
WWW=		https://github.com/greenbone/ospd-openvas

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=0:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecated>0:devel/py-deprecated@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR} \
		openvas:security/openvas

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	pep517

NO_ARCH=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME:S/-/_/}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-patch:
	${REINPLACE_CMD} -i "" '38d' ${WRKSRC}/pyproject.toml
	${REINPLACE_CMD} -i "" -e 's|/etc/openvas/gnupg|/var/lib/openvas/gnupg|g' \
		${WRKSRC}/ospd_openvas/gpg_sha_verifier.py
	${REINPLACE_CMD} -i "" -e 's|/run/ospd|/var/run/ospd|g' \
		${WRKSRC}/ospd/parser.py ${WRKSRC}/config/ospd-openvas.conf
post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/gvm
	@${INSTALL_DATA} ${WRKSRC}/config/ospd-openvas.conf ${STAGEDIR}${PREFIX}/etc/gvm/ospd-openvas.conf.sample
	@${MKDIR} ${STAGEDIR}/var/run/ospd

.include <bsd.port.mk>
