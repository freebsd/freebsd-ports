PORTNAME=	plumbum
PORTVERSION=	2.0.2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
MASTER_SITES=	PYPI

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shell combinators library
WWW=		https://github.com/tomerfiliba/plumbum

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-vcs>=0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	SSH

SSH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:security/py-paramiko@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
