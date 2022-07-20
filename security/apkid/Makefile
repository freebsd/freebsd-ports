PORTNAME=	APKiD
PORTVERSION=	2.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Android Application Identifier

LICENSE=	GPLv3 RedNaga
LICENSE_COMB=	dual
LICENSE_NAME_RedNaga=	Commercial
LICENSE_FILE_RedNaga=	${WRKSRC}/LICENSE.COMMERCIAL
LICENSE_PERMS_RedNaga=	pkg-mirror pkg-sell

USE_GITHUB=	yes
GH_ACCOUNT=	rednaga

USES=		python:3.7+
USE_PYTHON=	distutils

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yara-python-dex>0:security/py-yara-python-dex@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yara-python-dex>0:security/py-yara-python-dex@${PY_FLAVOR}

PLIST_SUB=	VER=${PORTVERSION}
NO_ARCH=	yes

post-install:
	(cd ${WRKSRC} && ${PYTHON_CMD} ./prep-release.py)
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/apkid/rules
	${CP} ${WRKSRC}/apkid/rules/rules.yarc	\
		${STAGEDIR}${PYTHON_SITELIBDIR}/apkid/rules/

.include <bsd.port.mk>
