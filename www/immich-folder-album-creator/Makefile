PORTNAME=	immich-folder-album-creator
DISTVERSION=	2.0.3
CATEGORIES=	www

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Create albums in Immich from a folder structure
WWW=		https://github.com/Salvoxia/immich-folder-album-creator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.8.4:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immichpy>=9.2.4<10:www/py-immichpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2026.9.29:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.2<10:devel/py-tenacity@${PY_FLAVOR}

USES=		python:3.11+,run

USE_GITHUB=	yes
GH_ACCOUNT=	Salvoxia

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	immich-auto-album pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

PLIST_FILES=	bin/immich-auto-album \
		${DATADIR_REL}/immich_auto_album.py

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/immich_auto_album.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/immich-auto-album ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
