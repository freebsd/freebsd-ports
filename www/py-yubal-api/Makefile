PORTNAME=	yubal-api
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
CATEGORIES=	www python
MASTER_SITES=	LOCAL/dtxdf/yubal/:assets
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
# For instructions on how to create assets:
#   https://github.com/DtxdF/port-assets-makejails/tree/main/yubal
DISTFILES=	yubal-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX}:assets

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Self-hosted YouTube Music downloader (API)

LICENSE=	MIT
LICENSE_FILE=	${WRKDIR}/yubal-${DISTVERSION}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>=0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}alembic>=0:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter>=0:sysutils/py-croniter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlmodel>=0:databases/py-sqlmodel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=0:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yubal>=0:www/py-yubal@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	guillevc
GH_PROJECT=	yubal
USE_PYTHON=	pep517
USE_RC_SUBR=	yubal

NO_ARCH=	yes
SUB_LIST=	HOMEDIR=${YUBAL_HOMEDIR} \
		USER=${YUBAL_USER}

WRKSRC_SUBDIR=	packages/api

USERS=		${YUBAL_USER}
GROUPS=		${YUBAL_GROUP}

PLIST_SUB=	GROUP=${YUBAL_GROUP} \
		HOMEDIR=${YUBAL_HOMEDIR} \
		USER=${YUBAL_USER}

YUBAL_USER=	www
YUBAL_GROUP=	www
YUBAL_HOMEDIR=	/var/db/yubal

post-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/web/dist
	@cd ${WRKDIR}/yubal-frontend && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/web/dist
	@${MKDIR} ${STAGEDIR}${YUBAL_HOMEDIR}

.include <bsd.port.mk>
