# $FreeBSD$

PORTNAME=	gitfs
DISTVERSION=	0.4.5.1
CATEGORIES=	sysutils devel
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Version controlled file system

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}atomiclong>0:devel/py-atomiclong \
		${PYTHON_PKGNAMEPREFIX}fusepy>=2.0.2:devel/py-fusepy \
		${PYTHON_PKGNAMEPREFIX}pygit2>=0.24.1:devel/py-pygit2 \
		${PYTHON_PKGNAMEPREFIX}raven>=5.27.0:devel/py-raven \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.6.1:devel/py-pytest

USE_GITHUB=	yes
GH_ACCOUNT=	PressLabs

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

post-patch:
	@${REINPLACE_CMD} -e 's/==/>=/' ${WRKSRC}/*requirements.txt

# XXX Integrations tests want MOUNT_PATH, REPO_* passed via TEST_ENV
do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest)

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:devel/py-mock
.else
post-patch:	patch-py3k-mock
patch-py3k-mock:
	@${GREP} -Flr 'mock import' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-i .bak.mock -e 's/mock import/unittest.&/'
.endif

.include <bsd.port.post.mk>
