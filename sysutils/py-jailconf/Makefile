PORTNAME=	jailconf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Parse and edit your FreeBSD jail.conf file

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>=3.9:devel/py-ply@${PY_FLAVOR}

USES=		python:3.3+
USE_GITHUB=	yes # tests nnot packaged in PyPI sdist
GH_ACCOUNT=	leforestier
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	${TOUCH} ${WRKSRC}/test/__init__.py
	${MV} ${WRKSRC}/test/jailconf_test.py ${WRKSRC}/test/test_jailconf.py
	cd ${WRKSRC} && ${PYTHON_CMD} -m unittest -v

.include <bsd.port.mk>
