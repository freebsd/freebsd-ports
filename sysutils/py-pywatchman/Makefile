PORTNAME=	pywatchman
DISTVERSIONPREFIX=v
DISTVERSION=	2024.03.25.00
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	p.mousavizadeh@protonmail.com
COMMENT=	Watchman client for Python
WWW=		https://pypi.org/project/pywatchman/

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

BROKEN_mips=	depends on watchman, which needs c++11-libs
BROKEN_mips64=	depends on watchman, which needs c++11-libs

RUN_DEPENDS=	watchman>=4:sysutils/watchman

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_PROJECT=	watchman
USE_PYTHON=	autoplist concurrent distutils

WRKSRC_SUBDIR=	watchman/python

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name "*.so" \
		-exec ${STRIP_CMD} {} +

do-test:
	cd ${WRKSRC} ; ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
