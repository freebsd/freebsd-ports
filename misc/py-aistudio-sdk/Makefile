PORTNAME=	aistudio-sdk # only available as a wheel, source code is in the wheel
DISTVERSION=	0.3.8
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
MASTER_SITE_SUBDIR=	cb/77/cd71a481bb7a76b0e9d0b6bf47711c627b1dd079001ea246893f19a9d04c/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aistudio_sdk-${PORTVERSION}-py3-none-any
EXTRACT_SUFX=	.whl

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library for the AIStudio API
WWW=		https://pypi.org/project/aistudio-sdk/

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}installer>0:devel/py-installer@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bce-python-sdk>=0.9:misc/py-bce-python-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR}

USES=		python zip
USE_PYTHON=	pep517 autoplist concurrent

NO_ARCH=	yes

WRKSRC=		${WRKDIR}

do-build:
	@${MKDIR} ${BUILD_WRKSRC}/dist
	@${CP} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${BUILD_WRKSRC}/dist/

.include <bsd.port.mk>
