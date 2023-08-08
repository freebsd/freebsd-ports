PORTNAME=	gitfs
DISTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	sysutils devel
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Version controlled file system
WWW=		https://www.presslabs.com/code/gitfs/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomiclong>=0.1.1:devel/py-atomiclong@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.12.3:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fusepy>=3.0.1:devel/py-fusepy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycparser>=2.19:devel/py-pycparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.28.2:devel/py-pygit2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}raven>=6.10.0:devel/py-raven@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.12.0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=4.6.5:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	PressLabs

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils concurrent optsuffix

post-patch:
	@${REINPLACE_CMD} -e 's/==/>=/' ${WRKSRC}/*requirements.txt

# XXX Integrations tests want MOUNT_PATH, REPO_* passed via TEST_ENV
do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

post-patch:	patch-py3k-mock
patch-py3k-mock:
	@${GREP} -Flr 'mock import' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-i .bak.mock -e 's/mock import/unittest.&/'

.include <bsd.port.mk>
