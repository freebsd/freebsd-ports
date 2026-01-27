PORTNAME=	flatnotes
DISTVERSIONPREFIX=	v
DISTVERSION=	5.5.4
CATEGORIES=	www python
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/:assets
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}:assets

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Self-hosted, database-less note taking web app

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>=0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyotp>=0:security/py-pyotp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-jose>=0:security/py-python-jose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=0:textproc/py-whoosh@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	dullage

USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes

SUB_LIST=	USER=${FLATNOTES_USER}

PLIST_SUB=	GROUP=${FLATNOTES_USER} \
		USER=${FLATNOTES_GROUP}

FLATNOTES_USER=		www
FLATNOTES_GROUP=	www
FLATNOTES_DATADIR=	/var/db/${PORTNAME}

do-build:
	@${PYTHON_CMD} -OO ${PYTHON_LIBDIR}/compileall.py \
		-d ${WWWDIR} \
		-f ${WRKSRC}/server

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/server && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}/client/dist
	@cd ${WRKDIR}/${PORTNAME}-frontend && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/client/dist
	@${MKDIR} ${STAGEDIR}${FLATNOTES_DATADIR}

.include <bsd.port.mk>
