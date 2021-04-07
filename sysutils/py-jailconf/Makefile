PORTNAME=	jailconf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Parse and edit your FreeBSD jail.conf file

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.9:devel/py-ply@${PY_FLAVOR}

USES=		python:3.0+
USE_GITHUB=	yes # tests nnot packaged in PyPI sdist
USE_PYTHON=	autoplist distutils

#LICENSE=	"BSD". Unclear. See Upstream #1
#LICENSE_FILE=	Does not exist

GH_ACCOUNT=	leforestier

NO_ARCH=	yes

do-test:
	${TOUCH} ${WRKSRC}/test/__init__.py
	${MV} ${WRKSRC}/test/jailconf_test.py ${WRKSRC}/test/test_jailconf.py
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
