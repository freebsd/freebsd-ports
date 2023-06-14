PORTNAME=	tvdb_api
PORTVERSION=	3.1.0
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/dbr/${PORTNAME}/commit/
PATCHFILES+=	f8db8e91377b30a6da078a43467ebf2f3b38227e.patch:-p1 \
				a346a0bb4348d084de767d235e028b9207e123c1.patch:-p1

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	API interface to TheTVDB.com
WWW=		https://pypi.org/project/tvdb_api/

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/UNLICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests-cache93>=0.9.3:www/py-requests-cache93@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
